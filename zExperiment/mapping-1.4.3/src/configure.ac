AC_PREREQ([2.67])
AC_INIT([Octave-Forge mapping package], [1.4.2])
AC_CONFIG_HEADERS([config.h])

AC_ARG_VAR([MKOCTFILE], [Compiler for Octave dynamic-load modules (default=mkoctfile -Wall)])
if test -z "$MKOCTFILE"; then
  MKOCTFILE='mkoctfile -Wall'
fi
AC_ARG_VAR([OCTAVE], [Octave executable for the installation (default=octave)])
if test -z "$OCTAVE"; then
  OCTAVE=octave
fi

HAS_RAD2DEG=`$OCTAVE -qf --eval "printf ('%i', exist ('rad2deg'))"`
HAS_DEG2RAD=`$OCTAVE -qf --eval "printf ('%i', exist ('deg2rad'))"`

if test "$HAS_RAD2DEG" == 0; then
  AC_CONFIG_FILES([rad2deg.m])
fi
if test "$HAS_DEG2RAD" == 0; then
  AC_CONFIG_FILES([deg2rad.m])
fi

AC_PROG_CXX
AC_LANG(C++)


## Older versions of gdal did not support pkg-config.  Instead, they
## wrote their own application, gdal-config, to do the same thing.
## So we first try pkg-config and if that fails, check for gdal-config.

PKG_CHECK_MODULES(GDAL, [gdal], [have_gdal=yes], [have_gdal=no])
if test $have_gdal = no; then
  AC_ARG_VAR([GDAL_CONFIG], [path to gdal-config utility])
  AC_CHECK_PROG([GDAL_CONFIG], gdal-config, gdal-config, [])
  if test -n "$GDAL_CONFIG"; then
    have_gdal=yes
    GDAL_LIBS=`gdal-config --libs`
    GDAL_CFLAGS=`gdal-config --cflags`
    AC_CHECK_LIB(gdal, [GDALAllRegister])
  fi
  AC_SUBST(GDAL_LIBS)
  AC_SUBST(GDAL_CFLAGS)
fi

if test $have_gdal = yes; then
  AC_DEFINE(HAVE_GDAL, 1, [Define to 1 if gdal is present.])
else
  AC_MSG_WARN([GDAL library not found.  Reading of raster files will be disabled.])
fi


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
