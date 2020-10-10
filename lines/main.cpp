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

void DAA(GLfloat x_1, GLfloat y_1, GLfloat x_2, GLfloat y_2, double length){

    glVertex2f(x_1, y_1);
    glVertex2f(x_2, y_2);

    GLfloat dx = x_2 - x_1;
    GLfloat dy = y_2 - y_1;

    GLfloat step;

    if(abs(dx) > abs(dy)){
        step = abs(dx);
    }else{
        step = abs(dy);
    }

    GLfloat xstep = dx / step;
    GLfloat ystep = dy / step;

    cout << "x_1 = " << x_1 << "   " << " y_1 = " << y_1 << endl;
    cout << "x_2 = " << x_2 << "   " << " y_2 = " << y_2 << endl;
    cout << "dx = " << dx << "    " << " dy = " << dy << endl;
    cout << "step = " << step << endl;
    cout << "xstep = " << xstep << " " << " ystep = " << ystep << endl;
    cout << endl;

    for(double i = 0.0; i <= step; i += 1 / length){
        cout << x_1 << " " << y_1 << endl;
        glVertex2f(x_1, y_1);
        x_1 += xstep / length; //se quita el round para que quede en la escala de 0 a 1
        y_1 += ystep / length;
    }
    //cout << "===========================" << endl;
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); //GL_LINES

    double l = 100;
    //2,3 8,15


    DAA(0.02, 0.03, 0.08, 0.15, l);
    /*
    DAA(0.0, 0.0, 0.8, 0.8, 1);
    DAA(0.0, 0.0, 0.8, -0.8, 300);

    DAA(0.0, 0.0, 0.6, 0.8, l);
    DAA(0.0, 0.0, 0.6, -0.8, l);

    DAA(-0.8, 0.8, 0.0, 0.0, l);
    DAA(-0.8, -0.8, 0.0, 0.0, l);

    DAA(-0.6, 0.8, 0.0, 0.0, l);
    DAA(-0.6, -0.8, 0.0, 0.0, l);

    DAA(-0.8, 0.0, 0.8, 0.0, l);
    DAA(0.0, 0.8, 0.0, -0.8, l);
*/
    //drawLine(-0.8, 0.8, 0.8, 0.8, l);
    //drawLine(0.8, 0.8, 0.0, 0.0, l);
    //drawLine(-0.8, 0.8, 0.0, 0.0, l);
    //drawLine(-0.8, -0.8, 0.0, 0.0, l);

    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Lines");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

