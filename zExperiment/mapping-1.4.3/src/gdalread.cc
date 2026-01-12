/*
The MIT License (MIT)

Copyright (C) 2015-2022 Shashank Khare, skhare at hotmail dot com
Copyright (C) 2015-2022 Philip Nienhuis <prnienhuis@users.sf.net>
Large parts of the below code originate from http://www.gdal.org/gdal_tutorial.html
(nowadays https://gdal.org/tutorials/raster_api_tut.html)

Acknowledgement: Snow and Avalanche Studies Establishment, DRDO, Chandigarh, India

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifdef HAVE_CONFIG_H
#include "./config.h"
#endif

#include <octave/oct.h>
#include <octave/ov-struct.h>
#include <octave/oct-map.h>
#include <octave/error.h>

#include <cstring>
#include "misc.h"
#include "stdio.h"

#ifdef HAVE_GDAL
#include <gdal_priv.h>
#include <cpl_conv.h>
#endif


/*
INPUT : string filepath
RETURNS: int containing return code,
         struct array containing band data,
         struct array containing metadata
*/

/*
See code examples here [1]:
http://www.gdal.org/gdal_tutorial.html
*/

DEFUN_DLD (gdalread, args, ,
           "-*- texinfo -*-\n\
@deftypefn  {} {[@var{rstat}, @var{rinfo}, @var{bands}] =} gdalread (@var{fname})\n\
@deftypefnx {} {[@var{rstat}, @var{rinfo}, @var{bands}] =} gdalread (@var{fname}, @var{info})\n\
Get raster data and info or (optionally) just info from a GIS raster file.\n\
For normal raster data reading it is better to use rasterread.m as that \n\
takes care of postprocessing gdalread output.\n\
\n\
@var{fname} is the name (or full path name) of a raster file to be read.\n\
\n\
@var{info} is any non-null value.  If present, only raster info is\n\
returned.  This option can be useful if only raster information is\n\
required and reading the raster data can be skipped.\n\
\n\
@var{rstat} is set to zero if reading was successful, -1 otherwise.\n\
\n\
@var{rinfo} is a scalar struct containing information about the raster\n\
data: datatype_index (a numerical GDAL datatype index); datatype_name\n\
(GDAL type name); BitDepth; geotransformation (1x6 double vector);\n\
projection (a string containing projection information); Width (nr. of\n\
raster data columns); Height (nr. of raster data rows); FileType; and\n\
nbands (the number of raster bands in the file).\n\
\n\
@var{bands} is a struct array containing raster data for each band in\n\
the file. If only raster info was requested, bands is empty.\n\
When data is read, each band is a struct element containing: bbox\n\
(bounding box: [xmin ymin; xmax ymax]), data (a matrix with the actual\n\
raster data); min (minimum raster data value); max (maximum raster\n\
data value); has_ndv (indicates whether the band as a special value\n\
indicating pixels that shouldn't be processed); ndv_val (the special\n\
value for improper pixels), and colortable.  If the band has a\n\
colortable, field ``colortable'' contains an Mx4 array of colortable\n\
entries (see GDAL reference), otherwise this field is empty.\n\
Note that the actual raster data array (field ``data'' is rotated\n\
90 degrees clockwise.\n\
@seealso{rasterread,rot90}\n\
@end deftypefn")

{
#ifndef HAVE_GDAL
  error ("gdalread: reading of raster file with GDAL was disabled during installation");
  return octave_value_list ();
#else

  int nargin = args.length ();
  octave_value_list ret_list(3);
  int num_items = 0;
  int XSize = 0, YSize = 0;

  if (nargin < 1)
  {
    get_null_values (3, &ret_list);
    print_usage ();
    return ret_list;
  };

  // [1] "Opening the file"
  std::string arg_file = args(0).string_value ();
  GDALDataset* poDS;
  GDALAllRegister ();
  poDS = (GDALDataset*) GDALOpen (arg_file.c_str(), GA_ReadOnly);
  if (poDS == NULL)
  {
    octave_stdout << "Error: Open failed.\n";
    get_null_values (3, &ret_list);
    return ret_list;
  }

  // [1] "Getting dataset information"
  double adfGeoTransform[6];
  int rasterX;                        // = poDS->GetRasterXSize();
  int rasterY;                        // = poDS->GetRasterYSize();
  octave_idx_type band_count = poDS->GetRasterCount ();

  if (!(poDS->GetGeoTransform(adfGeoTransform) == CE_None))
  {
    // error could not get geotransformation data
    // put origin as 0,0 and pixel size as 1,1
    // should not happen but if it does proceed with 0,0 as origin
    octave_stdout << "Warning: GetGeoTransform failed.\n";
    adfGeoTransform[0] = 0;
    adfGeoTransform[3] = 0;
    adfGeoTransform[1] = 1;
    adfGeoTransform[5] = 1;
  }

  /************************READING RASTER DATA **********************/
  GDALRasterBand* poBand;
  int raster_data_type, raster_type_size;
  const char* raster_type_name;

  // Only get raster data when no info request was given
  if (nargin <= 1)
  {
    static const char *fields[] = {"bbox", "data", "min", "max",
                                   "has_ndv", "ndv_val", "colortable", 0};
    // Output struct
    octave_map m_band (dim_vector (band_count, 1), string_vector (fields));
    octave_scalar_map band_struct = (string_vector (fields));

    // temp variables in below loop
    int nBlockXSize, nBlockYSize;
    int bGotMin, bGotMax;
    double adfMinMax[2];
    Matrix raster_data, raster_data_tmp, X_tmp, Y_tmp, colortable;
    Matrix bbox(2, 2);

    int clrs;
    GDALColorTable* GDALclr_table;
    const GDALColorEntry* clr_entry;

    for (octave_idx_type curr_band = 0; curr_band < band_count; curr_band++)
    {
      // [1] "Fetch a raster band"
      // Get actual raster data
      poBand = poDS->GetRasterBand (curr_band + 1);
      poBand->GetBlockSize (&nBlockXSize, &nBlockYSize);

      raster_data_type = (int)poBand->GetRasterDataType ();
      raster_type_name = GDALGetDataTypeName (poBand->GetRasterDataType ());
      raster_type_size = (int)GDALGetDataTypeSize (poBand->GetRasterDataType ());

      adfMinMax[0] = poBand->GetMinimum (&bGotMin);
      adfMinMax[1] = poBand->GetMaximum (&bGotMax);
      if (!(bGotMin && bGotMax))
        GDALComputeRasterMinMax ((GDALRasterBandH)poBand, TRUE, adfMinMax);

      // Get colortable, if present
      clrs = 0;
      GDALclr_table = poBand->GetColorTable ();
      if (GDALclr_table != NULL)
      {
        clrs = GDALclr_table->GetColorEntryCount ();
        colortable = Matrix (dim_vector(clrs, 4));
        for (octave_idx_type c_entry = 0; c_entry < clrs; c_entry++)
        {
          clr_entry = GDALclr_table->GetColorEntry (c_entry);
          colortable(c_entry, 0) = (double) clr_entry->c1;
          colortable(c_entry, 1) = (double) clr_entry->c2;
          colortable(c_entry, 2) = (double) clr_entry->c3;
          colortable(c_entry, 3) = (double) clr_entry->c4;
        }
      }
      else
        int colortable = -1;

      /******************* READING RASTER DATA *******************************************/
      rasterX = poBand->GetXSize ();
      rasterY = poBand->GetYSize ();
      ///////////////////////////////////////////////////
      raster_data = Matrix(dim_vector(rasterX, rasterY));

      long int nXBlocks = (rasterX + nBlockXSize - 1) / nBlockXSize;
      long int nYBlocks = (rasterY + nBlockYSize - 1) / nBlockYSize;

      // read the data into memory
      GByte* data_ptr = (GByte*) raster_data.fortran_vec ();
      long int* pafScanline = (long int*) CPLMalloc (sizeof (double) * rasterX * rasterY);
      long int read_size_x = 0, read_size_y = 0, nXOff, nYOff;
      CPLErr read_err =
        poBand->RasterIO (GF_Read, 0, 0, rasterX, rasterY, pafScanline, rasterX, rasterY, GDT_Float64, 0, 0);
      if (read_err != CE_None)
      {
        ret_list(0) = -1;
        return ret_list;
      }
      // TODO: memcpy is not needed
      memcpy (data_ptr, pafScanline, sizeof (double) * rasterX * rasterY);

      /************ calculate bounds for the band  *********************/
      double minx = adfGeoTransform[0];
      double maxy = adfGeoTransform[3];
      double maxx = minx + adfGeoTransform[1] * rasterX;
      double miny = maxy + adfGeoTransform[5] * rasterY;
      bbox(0, 0) = minx;
      bbox(0, 1) = miny;
      bbox(1, 0) = maxx;
      bbox(1, 1) = maxy;

      band_struct.setfield ("bbox", bbox);
      band_struct.setfield ("data", raster_data);
      band_struct.setfield ("min",  adfMinMax[0]);
      band_struct.setfield ("max",  adfMinMax[1]);

      int ndv_present = 0;
      double ndvalue = poBand->GetNoDataValue(&ndv_present);
      if (ndv_present)
        band_struct.setfield ("has_ndv", ndv_present);
      else
        band_struct.setfield ("has_ndv", -1);
      band_struct.setfield ("ndv_val", ndvalue);
      band_struct.setfield ("colortable", colortable);

      // Assign temp struct to output struct
      m_band.fast_elem_insert (curr_band, band_struct);

      CPLFree (pafScanline);
    }
    ret_list(2) = octave_value(m_band);
  }
  else
  {
    // Get raster info
    poBand = poDS->GetRasterBand (1);
    raster_data_type = (int)poBand->GetRasterDataType ();
    raster_type_name = GDALGetDataTypeName (poBand->GetRasterDataType ());
    raster_type_size = (int)GDALGetDataTypeSize (poBand->GetRasterDataType ());
    rasterX = poBand->GetXSize ();
    rasterY = poBand->GetYSize ();
    ret_list(2) = -1;
  }

  /*********************** generate meta data **************/
  Matrix geom(1, 6);
  geom(0, 0) = adfGeoTransform[0];
  geom(0, 1) = adfGeoTransform[1];
  geom(0, 2) = adfGeoTransform[2];
  geom(0, 3) = adfGeoTransform[3];
  geom(0, 4) = adfGeoTransform[4];
  geom(0, 5) = adfGeoTransform[5];

  // Output info struct
  octave_scalar_map meta_data;

  meta_data.assign(std::string("FileType"), 
    poDS->GetDriver()->GetMetadataItem (GDAL_DMD_LONGNAME));
  meta_data.assign(std::string("datatype_index"), raster_data_type);
  meta_data.assign(std::string("datatype_name"), raster_type_name);
  meta_data.assign(std::string("BitDepth"), raster_type_size);
  meta_data.assign(std::string("GeoTransformation"), geom);
  meta_data.assign(std::string("Projection"), poDS->GetProjectionRef());
  meta_data.assign(std::string("Width"), rasterX);
  meta_data.assign(std::string("Height"), rasterY);
  meta_data.assign(std::string("nbands"), band_count);

  ret_list(0) = octave_value(0);
  ret_list(1) = octave_value(meta_data);

  GDALClose ((GDALDatasetH) poDS);

  return ret_list;
#endif
}
