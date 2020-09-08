#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

void drawLine(GLfloat x_1, GLfloat y_1, GLfloat x_2, GLfloat y_2, double length){

    glVertex2f(x_1, y_1);
    glVertex2f(x_2, y_2);

    if (x_2 < x_1 ){
        GLfloat auxx = x_1;
        GLfloat auxy = y_1;
        x_1 = x_2;
        y_1 = y_2;
        x_2 = auxx;
        y_2 = auxy;
    }

    double m = (y_2 - y_1) / (x_2 - x_1) ;
    //double b = y_1 - (m * x_1);

    double increment = 1.0 / length;

    GLfloat y = y_1;

    for (GLfloat i = x_1; i < x_2; i += increment){
       cout << i << " " << y / length << endl;
       glVertex2f(i, y / length) ;
       y = y + m;
       //y = (m * i) + b;
    }
    cout << "===========================" << endl;

}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);

    double l = 150;

    drawLine(0.0, 0.0, 1.0, 1.0, l);
    drawLine(0.0, 0.0, 0.8, -0.8, l);

    drawLine(0.0, 0.0, 0.6, 0.8, l);
    drawLine(0.0, 0.0, 0.6, -0.8, l);

    drawLine(0.4, 0.4, 0.8, 0.8, l);

    //drawLine(-0.8, 0.8, 0.8, 0.8, l);
    //drawLine(0.8, 0.8, 0.0, 0.0, l);
    //drawLine(-0.8, 0.8, 0.0, 0.0, l);
    //drawLine(-0.8, -0.8, 0.0, 0.0, l);

    glEnd();
    glFlush();
}
/*
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Lines");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

*/
