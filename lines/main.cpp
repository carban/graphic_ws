#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

GLfloat x1=0.0,y_1=0.0,x2=0.8,y2=0.8;

void display(void) {
     glClear(GL_COLOR_BUFFER_BIT);

     glBegin(GL_POINTS);

     glVertex2f(x1, y_1);
     glVertex2f(x2, y2);

     double m = (y2 - y_1) / (x2 - x1) ;

     GLfloat y = y_1;

     for (GLfloat i = x1; i < x2; i += 0.001){
        cout << i << " " << y << endl;
        glVertex2f(i, y / 1000) ;
        y = y + m;
     }

     glEnd();
     glFlush();
}

int main(int argc, char* argv[]) {
    //string titulo = "("+string(argv[1]) +","+ string(argv[2]) +") - ("+ string(argv[3]) +","+ string(argv[4]) + ")";
    /*
    x1 =atof(argv[1]);
    y_1 = atof(argv[2]);
    x2 = atof(argv[3]);
    y2 = atof(argv[4]);
    */
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("asasa");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

