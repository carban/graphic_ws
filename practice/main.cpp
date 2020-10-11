#include <GL/glut.h>
#include <cstdio>

void freeDraw(){

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
        glVertex3d(0.0,0.0,0.0);
        glVertex3d(0.0,0.0,1.0);
        glVertex3d(0.0,0.0,1.0);
        glVertex3d(1.0,0.0,1.0);
        glVertex3d(1.0,0.0,1.0);
        glVertex3d(0.0,0.0,0.0);
    glEnd();
}


void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glutWireTorus(0.25,0.75, 28, 28);
    glColor3f(0.0,0.0,1.0);
    glutWireCube(.60);
    freeDraw();
    glColor3f(0.0,0.0,0.0);
    glutWireSphere(0.2,20,20);
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'h':
            printf("help\n\n");
            printf("c - Toggle culling\n");
            printf("q/escape - Quit\n\n");
        break;
        case 'c':
            if (glIsEnabled(GL_CULL_FACE))
                glDisable(GL_CULL_FACE);
            else
                glEnable(GL_CULL_FACE);
            break;
        case '1':
            glRotatef(1.0,1.0,0.0,0.0);
            break;
        case '2':
            glRotatef(1.0,0.0,1.0,0.0);
            break;
        case '3':
            glRotatef(-1.0,1.0,0.0,0.0);
            break;
        case '4':
            glRotatef(-1.0,0.0,1.0,0.0);
            break;
        case 'w':
            gluLookAt(1.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.1, 0.0, 0.0);
            break;
        case 'q':
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(512, 512);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("OpenGL program");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
