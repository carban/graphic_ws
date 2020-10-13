#include <GL/glut.h>
#include <cstdio>
#include <math.h>

void drawCircle(float r){
    glColor3f(0.6,0.6,0.6);
    glPushMatrix();
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for(int i =0; i <= 360; i++){
        double angle = 2 * M_PI * i / 360;
		double x = r * cos(angle);
		double y = r * sin(angle);
		glVertex2d(x + 0.0, y + 0.0);
    }
    glEnd();
    glPopMatrix();
}

void drawSolarSystem(){

    double dist = 0.35;
    double increment = 0.08;

    // Sun -------------------------------------------

    glColor3f(1.0,0.8,0.0);
    glPushMatrix();
    glutWireSphere(0.15,60,60);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glutWireSphere(0.2,30,30);
    glPopMatrix();

    // Mercury -------------------------------------------

    glColor3f(0.8,0.41,0.02);
    glPushMatrix();
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.02,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Venus -------------------------------------------

    dist += increment;

    glColor3f(0.6,0.8,0.02);
    glPushMatrix();
    glRotatef(60.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.025,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Earth -------------------------------------------

    dist += increment;

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glRotatef(180.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.035,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Mars -------------------------------------------

    dist += increment;

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glRotatef(330.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.03,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Jupyter -------------------------------------------

    dist += increment + 0.06;

    glColor3f(0.8,0.3,0.02);
    glPushMatrix();
    glRotatef(210.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.06,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Saturn -------------------------------------------

    dist += increment;

    glColor3f(0.8,0.3,0.05);
    glPushMatrix();
    glRotatef(50.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.030,30,30);
    glColor3f(0.9,0.7,0.0);
    glRotatef(90.0, 90.0, 0.0, 0.0);
    glutWireTorus(0.004,0.06, 30, 30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Uranus -------------------------------------------

    dist += increment;

    glColor3f(0.8,0.6,0.8);
    glPushMatrix();
    glRotatef(140.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.028,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Neptune -------------------------------------------

    dist += increment;

    glColor3f(0.4,0.3,1.0);
    glPushMatrix();
    glRotatef(300.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.028,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit

}

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSolarSystem();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
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
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(600, 200);
	glutCreateWindow("Solar System");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
