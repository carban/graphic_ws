#include <GL/glut.h>
#include<stdlib.h>
#include<math.h>

void myinit(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D (0.0,640.0,0.0,480.0);
 }

float xstart=-100,ystart=-100,xend=200,yend=200,step,xinc,yinc,x,y;

int Round(float a)			//any x i.e 1>=x>=0.5 is rounded to 1
{
  if(a-int(a)>=0.5)
  return int(a)+1;
  else
  return int(a);
     }

void drawline()
     {

       float ydiff = yend-ystart;
       float xdiff = xend-xstart;
       if (abs(xdiff) > abs(ydiff))
        step = abs(xdiff);                //assign abs(xdiff) to step if xdiff>ydiff
        else
        step = abs(ydiff);              //assign abs(ydiff) to step if xdiff<ydiff

        xinc = xdiff/step;            //assign xdiff/step to xinc
        yinc = ydiff/step;           //assign ydiff/step to yinc

        x = xstart;               //assign xstart to x
        y = ystart;              //assign ystart to y

for(int k=0;k<step;k++)
      {
       x = x+xinc;       // update x by xinc
       y = y+yinc;
	   glColor3f(0,0,1); // sets the current drawing (foreground) color to blue
		 glPointSize(10); // sets the size of points to be drawn (in pixels)
	   glBegin(GL_POINTS); // writes pixels on the frame buffer with the current drawing color
       glVertex2i(Round(x),Round(y));//sets vertex
          glEnd();
	 }
//glutPostRedisplay();


  }

void display2(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // clears the frame buffer and set values defined in glClearColor() function call
    drawline();
    glFlush(); // flushes the frame buffer to the screen
}
/*
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize(700,700);//sets the width and height of the window in pixels
    glutCreateWindow("DDA Line Drawing");//creates the window as specified by the user as above.
    glutDisplayFunc(display2);//links the display event with the display event handler(display)
	//myinit();
    glutMainLoop();//loops the current event
}
*/
