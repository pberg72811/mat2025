/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: sonogram.c
// Desc: This file contains the code for the sonogram binary.
// Hist: When       Who  What
//       09/14/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <Xm/Xm.h>
#include <Xm/PushB.h>
#include <Xm/DrawingA.h>
#include <Xm/RowColumn.h>
#include <Xm/Frame.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "iccswd.h"
#include "iccStackUtils.h"
#include "iccDSPUtils.h"
#include "iccXUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define FRAME_WIDTH      (512)
#define N_PLATES         (3)
#define FFT_SIZE         (128)
#define UPSAMPLEBY       (1)
#define INPUT_BLOCK_SIZE (FRAME_WIDTH*FFT_SIZE*N_PLATES/UPSAMPLEBY)
#define INT08INPUT       0
#define INT16INPUT       1
#define INT32INPUT       2
#define FLT32INPUT       34
#define TEST_MOTIF_FUNC_DESC \
"********************************************************************************\n"\
"This routine displays a sonogram image of the input data.                       \n"\
"                                                                                \n"\
"Input : is from stdin and needs to be 16t format.                               \n"\
"                                                                                \n"\
"Output: is to stdout.                                                           \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  NONE                                                                          \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  -h, or --help                                                                 \n"\
"  -08t and -SB will process  8 bit data.                                        \n"\
"  -16t and -SI will process 16 bit data.                                        \n"\
"********************************************************************************\n"\
"\n"

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  INT08 iData08[INPUT_BLOCK_SIZE];
  INT16 iData16[INPUT_BLOCK_SIZE];
  FLT32 iData32[INPUT_BLOCK_SIZE];
  FLT32 uData32[INPUT_BLOCK_SIZE*UPSAMPLEBY];
  FLT32 wData32[FFT_SIZE];
  FLT32 oData32[FFT_SIZE*2];
  UNT32 blockCounter;
  UNT32 byteCounter;
  INT32 amountRead;
  INT32 inputDataType;
  FILE     *fp;
  iccXImage_t *p2iccXImage1;
  iccXImage_t *p2iccXImage2;
  iccXImage_t *p2iccXImage3;
  Window   image1ID;
  Window   image2ID;
  Window   image3ID;
  UNT32    scm[256]; //Sonogram Color Map
  Display  *display;
  INT32    screenNum;
  Colormap colormap;
  Window   shellWindow;
  GC       gc;
  Visual   *visual;
  iccStackUNT16_t *intensityStack;

}ThisStruct;

ThisStruct this;

// SonogramInit
//------------------------------------------------------------------------------
VOID SonogramInit(FILE *filePointer, INT32 inputDataType)
{
  this.intensityStack = iccStackInitUNT16(INPUT_BLOCK_SIZE*UPSAMPLEBY+128, "intesityStack");
  iccStackClearUNT16(this.intensityStack);
  this.blockCounter = 0;
  this.byteCounter = 0;
  this.fp = filePointer;
  this.inputDataType = inputDataType;
  iccvZeroINT08(this.iData08, 1, INPUT_BLOCK_SIZE);
  iccvZeroINT16(this.iData16, 1, INPUT_BLOCK_SIZE);
  iccvZeroFLT32(this.iData32, 1, INPUT_BLOCK_SIZE);
  iccvZeroFLT32(this.uData32, 1, INPUT_BLOCK_SIZE*UPSAMPLEBY);
  iccvZeroFLT32(this.wData32, 1, FFT_SIZE);
  iccvZeroFLT32(this.oData32, 1, FFT_SIZE*2);
}

// SonogramTerm
//------------------------------------------------------------------------------
VOID SonogramTerm()
{
  iccStackTermUNT16(this.intensityStack);
  iccXImageDestroy(this.p2iccXImage1);
  iccXImageDestroy(this.p2iccXImage2);
  iccXImageDestroy(this.p2iccXImage3);
}

// SonogramReadTheData
//------------------------------------------------------------------------------
VOID SonogramReadTheData(VOID)
{
  if     ( this.inputDataType == INT08INPUT )
  {
    this.amountRead = fread(this.iData08, sizeof(this.iData08[0]), INPUT_BLOCK_SIZE, this.fp);
    this.blockCounter++;
    this.byteCounter = this.blockCounter*sizeof(this.iData08[0])*INPUT_BLOCK_SIZE;
  }
  else if( this.inputDataType == INT16INPUT )
  {
    this.amountRead = fread(this.iData16, sizeof(this.iData16[0]), INPUT_BLOCK_SIZE, this.fp);
    this.blockCounter++;
    this.byteCounter = this.blockCounter*sizeof(this.iData16[0])*INPUT_BLOCK_SIZE;
  }
  else
  {
    this.amountRead = fread(this.iData16, sizeof(this.iData16[0]), INPUT_BLOCK_SIZE, this.fp);
    this.blockCounter++;
    this.byteCounter = this.blockCounter*sizeof(this.iData16[0])*INPUT_BLOCK_SIZE;
  }
}

// SonogramConvertTheData
//------------------------------------------------------------------------------
VOID SonogramConvertTheData(VOID)
{
  if     ( this.inputDataType == INT08INPUT )
  {
    iccvINT08ToFLT32( this.iData08, 1, this.iData32, 1, this.amountRead );
  }
  else if( this.inputDataType == INT16INPUT )
  {
    iccvINT16ToFLT32( this.iData16, 1, this.iData32, 1, this.amountRead );
  }
  else
  {
    iccvINT16ToFLT32( this.iData16, 1, this.iData32, 1, this.amountRead );
  }
  iccvZeroFLT32(this.uData32, 1, this.amountRead*UPSAMPLEBY);
  iccvCopyFLT32(this.iData32, 1, this.uData32, UPSAMPLEBY, this.amountRead);
}

// SonogramProcessTheData
//------------------------------------------------------------------------------
VOID SonogramProcessTheData(VOID)
{
  INT32 ii;
  INT32 jj;
  FLT32 min;
  FLT32 max;
  UNT16 temp;
  for(ii=0; ii<(this.amountRead*UPSAMPLEBY/FFT_SIZE); ii++)
  {
    /* Window the data with a Blackman window. */
    iccBlackmanWindowFLT32(&this.uData32[ii*FFT_SIZE], 1, &this.wData32[0], 1, FFT_SIZE);
    //iccvBoxcarWindowFLT32(&this.uData32[ii*FFT_SIZE], 1, &this.wData32[0], 1, FFT_SIZE);

    /* Perform the FFT. */
    iccFFTFLT32_R( &this.wData32[0], //Real input.
		   &this.oData32[0], //Complex output.
		   FFT_SIZE);        //Number of elements.                                                    
    
    /* Normalize the data */
    this.oData32[0] = this.oData32[1] = 0.0; // Zero out DC.
    min = 1.0;
    max = 1.0;
    for(jj=1; jj< FFT_SIZE/2; jj++)
    {
      this.oData32[jj] = this.oData32[jj*2+0]*this.oData32[jj*2+0] +
                         this.oData32[jj*2+1]*this.oData32[jj*2+1];
      this.oData32[jj] = sqrt(this.oData32[jj]);
      
      if( this.oData32[jj] < min ) min = this.oData32[jj];
      if( this.oData32[jj] > max ) max = this.oData32[jj];
    }
    
    /* Push the data onto the stack */
    for(jj=0; jj<FFT_SIZE/2; jj++)
    {
      temp = (UNT16) (255*(this.oData32[jj]+min)/max);
      iccStackPushUNT16( this.intensityStack, temp );
    }
  }
}

// SonogramDisplayTheData
//------------------------------------------------------------------------------
VOID SonogramDisplayTheData(void)
{
  INT32 ii;
  INT32 jj;
  UNT16 value;

  iccStackFlipUNT16(this.intensityStack);

  for(ii = 0; ii<FRAME_WIDTH; ii++)
  {
    for(jj = 0; jj<(FFT_SIZE/2); jj++)
    {
      iccStackPopUNT16(this.intensityStack, &value);
      XPutPixel(this.p2iccXImage1->p2XImage, ii, jj, this.scm[value]);
    }
  }

  for(ii = 0; ii<FRAME_WIDTH; ii++)
  {
    for(jj = 0; jj<(FFT_SIZE/2); jj++)
    {
      iccStackPopUNT16(this.intensityStack, &value);
      XPutPixel(this.p2iccXImage2->p2XImage, ii, jj, this.scm[value]);
    }
  }

  for(ii = 0; ii<FRAME_WIDTH; ii++)
  {
    for(jj = 0; jj<(FFT_SIZE/2); jj++)
    {
      iccStackPopUNT16(this.intensityStack, &value);
      XPutPixel(this.p2iccXImage3->p2XImage, ii, jj, this.scm[value]);
    }
  }
}

// SonogramHandleForward
//------------------------------------------------------------------------------
VOID SonogramHandleForward(Widget w, XtPointer p1, XtPointer p2)
{
  SonogramReadTheData();
  SonogramConvertTheData();
  SonogramProcessTheData();
  SonogramDisplayTheData();
  iccSendExposeXEvent(this.display, this.image1ID);
  iccSendExposeXEvent(this.display, this.image2ID);
  iccSendExposeXEvent(this.display, this.image3ID);
  printf("Going Forward!\n");
}

// SonogramHandleReverse
//------------------------------------------------------------------------------
VOID SonogramHandleReverse(Widget w, XtPointer p1, XtPointer p2)
{
  if(this.blockCounter>1)
  {
    this.blockCounter--;
    this.blockCounter--;
    this.byteCounter = this.blockCounter*sizeof(this.iData16[0])*INPUT_BLOCK_SIZE;
    fseek(this.fp, this.byteCounter, SEEK_SET);
    SonogramReadTheData();
    SonogramConvertTheData();
    SonogramProcessTheData();
    SonogramDisplayTheData();
    iccSendExposeXEvent(this.display, this.image1ID);
    iccSendExposeXEvent(this.display, this.image2ID);
    iccSendExposeXEvent(this.display, this.image3ID);
    printf("Reverse!\n");
  }
  else return;
}

// SonogramHandleQuit
//------------------------------------------------------------------------------
void SonogramHandleQuit(Widget w, XtPointer p1, XtPointer p2)
{
  printf("Quit!\n");
  SonogramTerm();
  exit(0);
}

// handleDraw1
//------------------------------------------------------------------------------
void handleDraw1(Widget w, XtPointer p1, XtPointer p2)
{
  if(this.image1ID == 0) this.image1ID = XtWindow(w);
  XPutImage(this.display, this.image1ID, this.gc, this.p2iccXImage1->p2XImage, 0, 0, 0, 0, FRAME_WIDTH, FFT_SIZE);
  printf("Exposed1\n");
}

// handleDraw2
//------------------------------------------------------------------------------
void handleDraw2(Widget w, XtPointer p1, XtPointer p2)
{
  if(this.image2ID == 0) this.image2ID = XtWindow(w);
  XPutImage(this.display, this.image2ID, this.gc, this.p2iccXImage2->p2XImage, 0, 0, 0, 0, FRAME_WIDTH, FFT_SIZE);
  printf("Exposed2\n");
}

// handleDraw3
//------------------------------------------------------------------------------
void handleDraw3(Widget w, XtPointer p1, XtPointer p2)
{
  if(this.image3ID == 0) this.image3ID = XtWindow(w);
  XPutImage(this.display, this.image3ID, this.gc, this.p2iccXImage3->p2XImage, 0, 0, 0, 0, FRAME_WIDTH, FFT_SIZE);
  printf("Exposed3\n");
}

// main
//------------------------------------------------------------------------------
int main(int argc, char **argv)
{
  XtAppContext appContext;
  Widget shellWidget;
  Widget forwardButton;
  Widget reverseButton;
  Widget quitButton;
  Widget drawing1, drawing2, drawing3;
  Widget rowcolManager1;
  Widget rowcolManager2;
  Widget frame1, frame2;
  Widget frame3, frame4;
  XmString label;
  INT32 ii;
  //INT32 socketFID;
  //struct sockaddr_in myAddr;
  //char c='a';
  //iccStackINT08_t *theStack;
  CHR08 colorString[128];
  INT32 inputDataType=INT16INPUT;

  /* Handle input parameters -------------------------------------------------*/
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      printf(TEST_MOTIF_FUNC_DESC);
      exit(0);
    }
    if( !strncmp( argv[ii], "-SB",  3) ) inputDataType = INT08INPUT;
    if( !strncmp( argv[ii], "-SI",  3) ) inputDataType = INT16INPUT;
    if( !strncmp( argv[ii], "-08t", 4) ) inputDataType = INT08INPUT;
    if( !strncmp( argv[ii], "-16t", 4) ) inputDataType = INT16INPUT;

  }

  SonogramInit(stdin,inputDataType); printf("Sonogram Init\n");
  SonogramReadTheData(); printf("Sonogram Read\n");
  SonogramConvertTheData(); printf("Sonogram Convert\n");
  SonogramProcessTheData(); printf("Sonogram Process\n");

  //theStack = iccStackInitINT08( 1024, "TheStack" );
  //iccCHR08UnpackMSB_INT08( theStack, c );
  //iccCHR08UnpackLSB_INT08( theStack, c );

  //myAddr = (struct sockaddr_in *)malloc(1024);
  //myAddr.sin_family = PF_INET;
  //myAddr.sin_port = htons(3500);
  //myAddr.sin_addr.s_addr = inet_addr("7.156.26.243");
  //memset(&(myAddr.sin_zero), '\0', 8);

  //socketFID = socket(PF_INET, SOCK_DGRAM, 0);
  //shutdown(socketFID,0);

  // Set up Motif widgets.
  /*--------------------------------------------------------------------------*/
  shellWidget = XtVaAppInitialize(&appContext, //Application context
				  "Hello",     //Class name of application
				  NULL,        //Commonad line list
				  0,           //Number in command line list
				  &argc,       //Command line args
				  argv,        //Number of command line args
				  NULL,        //Fall back resources
				  XmNwidth, FRAME_WIDTH+15,
				  XmNheight,500,
				  NULL);       //Resource-value pairs

  this.display     = XtDisplay(shellWidget);
  this.shellWindow = XtWindow(shellWidget);
  this.screenNum   = DefaultScreen(this.display);
  this.colormap    = DefaultColormap(this.display, this.screenNum);
  this.gc          = DefaultGC(this.display, this.screenNum);
  this.visual      = DefaultVisual(this.display, this.screenNum);
  for (ii = 0; ii < 256; ii++)
  {
    XColor xColor;
    sprintf(colorString,"RGBi:%f/%f/%f",ii*.00390625,ii*.00390625,ii*.00390625);
    XParseColor(this.display,
		this.colormap,
		colorString,
		&xColor);
    XAllocColor(this.display, this.colormap, &xColor);
    this.scm[ii] = xColor.pixel;
  }

  this.p2iccXImage1 = iccXImageCreate( this.display, 16, FRAME_WIDTH, FFT_SIZE/2 );
  this.p2iccXImage2 = iccXImageCreate( this.display, 16, FRAME_WIDTH, FFT_SIZE/2 );
  this.p2iccXImage3 = iccXImageCreate( this.display, 16, FRAME_WIDTH, FFT_SIZE/2 );

  SonogramDisplayTheData(); printf("Sonogram Display\n");


  rowcolManager1 = XtVaCreateManagedWidget("RowColumn1",   //Resource data base name
				   xmRowColumnWidgetClass, //Widget class to create
				   shellWidget,            //Parent
				   XmNlabelString, label,  //
				   NULL);                  //

  frame1 = XtVaCreateManagedWidget("Frame1",               //Resource data base name
		                   xmFrameWidgetClass,     //Widget class to create
				   rowcolManager1,         //Parent
				   XmNwidth, 490,          //
				   XmNheight,145,          //
				   NULL);                  //

  frame2 = XtVaCreateManagedWidget("Frame2",               //Resource data base name
		                   xmFrameWidgetClass,     //Widget class to create
				   rowcolManager1,         //Parent
				   XmNwidth, 490,          //
				   XmNheight,145,          //
				   NULL);                  //

  frame3 = XtVaCreateManagedWidget("Frame3",               //Resource data base name
		                   xmFrameWidgetClass,     //Widget class to create
				   rowcolManager1,         //Parent
				   XmNwidth, 490,          //
				   XmNheight,145,          //
				   NULL);                  //

  frame4 = XtVaCreateManagedWidget("Frame4",               //Resource data base name
		                   xmFrameWidgetClass,     //Widget class to create
				   rowcolManager1,         //Parent
				   XmNwidth, 490,          //
				   XmNheight, 45,          //
				   NULL);                  //

  drawing1 = XtVaCreateManagedWidget("DrawingArea1",         //Resource data base name
				   xmDrawingAreaWidgetClass, //Widget class to create
				   frame1,                   //Parent
				   XmNwidth, 490,            //
				   XmNheight,143,            //
				   XmNresizePolicy, XmNONE,  //
				   NULL);                    //

  drawing2 = XtVaCreateManagedWidget("DrawingArea2",         //Resource data base name
				   xmDrawingAreaWidgetClass, //Widget class to create
				   frame2,                   //Parent
				   XmNwidth, 490,            //
				   XmNheight,143,            //
				   XmNresizePolicy, XmNONE,  //
				   NULL);                    //

  drawing3 = XtVaCreateManagedWidget("DrawingArea3",         //Resource data base name
				   xmDrawingAreaWidgetClass, //Widget class to create
				   frame3,                   //Parent
				   XmNwidth, 490,            //
				   XmNheight,143,            //
				   XmNresizePolicy, XmNONE,  //
				   NULL);                    //

  rowcolManager2 = 
    XtVaCreateManagedWidget("RowColumn2",                   //Resource data base name
			    xmRowColumnWidgetClass,         //Widget class to create
			    frame4,                         //Parent
			    XmNrowColumnType, XmWORK_AREA,  //
			    XmNorientation,   XmHORIZONTAL, //
			    XmNspacing,       113,          //
			    NULL);                          //

  label  = XmStringCreateSimple("Forward >>> ");
  forwardButton = XtVaCreateManagedWidget("ForwardButton",  //Resource data base name
				   xmPushButtonWidgetClass, //Widget class to create
				   rowcolManager2,          //Parent
				   XmNlabelString, label,   //
				   NULL);                   //

  label  = XmStringCreateSimple("<<< Reverse ");
  reverseButton = XtVaCreateManagedWidget("ReverseButton",  //Resource data base name
				   xmPushButtonWidgetClass, //Widget class to create
				   rowcolManager2,          //Parent
				   XmNlabelString, label,   //
				   NULL);                   //

  label  = XmStringCreateSimple("    QUIT    ");
  quitButton = XtVaCreateManagedWidget("QuitButton",        //Resource data base name
				   xmPushButtonWidgetClass, //Widget class to create
				   rowcolManager2,          //Parent
				   XmNlabelString, label,   //
				   NULL);                   //

  XmStringFree(label);

  // Set up Motif widget callbacks. 
  /*--------------------------------------------------------------------------*/
  XtAddCallback(forwardButton,         //Widget that will call back
		XmNactivateCallback,   //Callback resource
		SonogramHandleForward, //Function to call back
		NULL);                 //Data to pass to Fuction

  XtAddCallback(reverseButton,        //Widget that will call back
		XmNactivateCallback,  //Callback resource
		SonogramHandleReverse,//Function to call back
		NULL);                //Data to pass to Fuction

  XtAddCallback(quitButton,          //Widget that will call back
		XmNactivateCallback, //Callback resource
		SonogramHandleQuit,  //Function to call back
		NULL);               //Data to pass to Fuction

  XtAddCallback(drawing1,          //Widget that will call back
		XmNexposeCallback, //Callback resource
		handleDraw1,       //Function to call back
		NULL);             //Data to pass to Fuction

  XtAddCallback(drawing2,          //Widget that will call back
		XmNexposeCallback, //Callback resource
		handleDraw2,       //Function to call back
		NULL);             //Data to pass to Fuction

  XtAddCallback(drawing3,          //Widget that will call back
		XmNexposeCallback, //Callback resource
		handleDraw3,       //Function to call back
		NULL);             //Data to pass to Fuction

  // Realize the widgets.
  /*--------------------------------------------------------------------------*/
  XtRealizeWidget(shellWidget);

  // Kick off the main loop. 
  /*--------------------------------------------------------------------------*/
  XtAppMainLoop(appContext);

  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
