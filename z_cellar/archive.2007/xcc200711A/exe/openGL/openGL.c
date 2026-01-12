/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: openGL.c
// Desc: This file contains the code for the openGL binary.
// Hist: When       Who  What
//       08/09/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "iccswd.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
static FLT32 spin = 0.0;

void init(void)
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0.5,0.0,0.0,0.0);
  glShadeModel(GL_SMOOTH);
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  glRotatef(spin, 0.0, 0.0, 1.0);
  glColor4f(1.0, 1.0, 1.0, 0.5);
  glRectf(-25.0, -25.0, 25.0, 25.0); 
  glPopMatrix();
  glutSwapBuffers();
}

void spinDisplay(void)
{
  spin = spin + 2.0;
  if(spin >= 360.0) spin = spin - 360.0;
  glutPostRedisplay();
}

void reshape(int w, int h)
{
  glViewport(0,0,(GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

static void key(unsigned char k, int x, int y)
{
  switch (k) {
  case 81:
    exit(0);
  }
}

static void mouse( int button, int state, int x, int y)
{
  //printf("Mouse button is %d\n", button);
  //printf("Mouse state  is %d\n", state);
  //printf("Mouse x      is %d\n", x);
  //printf("Mouse y      is %d\n", y);
  switch(button)
  {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN) glutIdleFunc(spinDisplay);
      break;
    case GLUT_RIGHT_BUTTON:
      if (state == GLUT_DOWN) glutIdleFunc(NULL);
      break;
    default:
      break;
  }
}

static void motion( int x, int y)
{
  //printf("Motion x is %d\n",x);
  //printf("Motion y is %d\n",y);
}

static void passiveMotion( int x, int y)
{
  //printf("Passive motion x is %d\n",x);
  //printf("Passive motion y is %d\n",y);
}

int main(  int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(250,250);
  glutInitWindowPosition(100,100);
  glutCreateWindow("First Window");
  init();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(key);
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
  glutPassiveMotionFunc(passiveMotion);
  glutMainLoop();
  return 0;
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
