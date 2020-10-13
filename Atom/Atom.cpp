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

void drawPlanet(float dist, float r, float g, float b, float length, float pos){

    glColor3f(r, g, b);
    glPushMatrix();
    glRotatef(pos, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(length,30,30);
    glPopMatrix();

    drawCircle(dist); // Orbit
}

void drawSolarSystem(){

    float dist = 0.35;
    float increment = 0.08;

    // Core -------------------------------------------

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glutWireSphere(0.05,60,60);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.03, 0.03, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.03, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(0.06, 0.00, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glTranslatef(-0.03, -0.03, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.03, 0.05, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    glColor3f(0.0,0.0,1.0);
    glPushMatrix();
    glTranslatef(0.05, -0.03, 0.0);
    glutWireSphere(0.05,20,20);
    glPopMatrix();

    float len = 0.02;

    // Layer 1 -------------------------------------------

    drawPlanet(dist, 0.0, 0.0, 0.5, len, 22.0);
    drawPlanet(dist, 0.0, 0.0, 0.5, len, 202.0);

    // Layer 2 -------------------------------------------

    dist += increment;
    float angle = 45;
    for(int i = 0; i < 8; i++){
        drawPlanet(dist, 0.0, 0.0, 0.5, len, angle);
        angle += 45;
    }

    // Layer 3 -------------------------------------------

    dist += increment;
    drawPlanet(dist, 0.0, 0.0, 0.5, len, 112.0);
    drawPlanet(dist, 0.0, 0.0, 0.5, len, 292.0);
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSolarSystem();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(20.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
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
	glutCreateWindow("Atom");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
