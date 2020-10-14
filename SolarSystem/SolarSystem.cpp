#include <GL/glut.h>
#include <cstdio>
#include <math.h>

void drawCircle(float r){

    glColor3f(0.6,0.6,0.6);
    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
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
    glutSolidSphere(length, 30.0, 30.0 );
    glPopMatrix();

    drawCircle(dist); // Orbit
}

void drawSolarSystem(){

    float dist = 0.35;
    float increment = 0.08;

    // Sun -------------------------------------------

    glColor3f(1.0,0.8,0.0);
    glPushMatrix();
    glutWireSphere(0.17,60,60);
    glPopMatrix();

    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
    glutWireSphere(0.2,20,20);
    glPopMatrix();

    // Mercury -------------------------------------------

    drawPlanet(dist, 0.8, 0.41, 0.02, 0.02, 1.0);

    // Venus -------------------------------------------

    dist += increment;
    drawPlanet(dist, 0.6, 0.8, 0.02, 0.025, 60.0);

    // Earth -------------------------------------------

    dist += increment;
    drawPlanet(dist, 0.0, 0.0, 1.0, 0.038, 180.0);

    // Mars -------------------------------------------

    dist += increment;
    drawPlanet(dist, 1.0, 0.0, 0.0, 0.033, 330.0);

    // Jupyter -------------------------------------------

    dist += increment + 0.06;
    drawPlanet(dist, 0.8, 0.3, 0.02, 0.064, 210.0);

    // Saturn -------------------------------------------

    dist += increment;

    glColor3f(0.8,0.3,0.05);
    glPushMatrix();
    glRotatef(50.0, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutWireSphere(0.035,30,30);
    glColor3f(0.9,0.7,0.0);
    glRotatef(90.0, 90.0, 0.0, 0.0);
    glutWireTorus(0.004,0.06, 30, 30);
    glPopMatrix();

    drawCircle(dist); // Orbit

    // Uranus -------------------------------------------

    dist += increment;
    drawPlanet(dist, 0.8, 0.6, 0.8, 0.028, 140.0);

    // Neptune -------------------------------------------

    dist += increment;
    drawPlanet(dist, 0.4, 0.3, 1.0, 0.03, 300.0);

}

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawSolarSystem();
    glutSwapBuffers();
}

void reshape(int width, int height) {

	if (width <= height){
		glViewport(0, 0, width, width);
	}else {
		glViewport(0, 0, height, height);
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            glRotatef(1.0,1.0,0.0,0.0);
            break;
        case '2':
            glRotatef(1.0,0.0,1.0,0.0);
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
