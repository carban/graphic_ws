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

void drawElectron(float dist, float length, float pos){

    glColor3f(0.5, 0.5, 0.5);
    glPushMatrix();
    glRotatef(pos, 0.0, 1.0, 0.0);
    glTranslatef(dist, 0.0, 0.0);
    glutSolidSphere(length, 30.0, 30.0 );
    glPopMatrix();

    drawCircle(dist); // Orbit
}

void drawProtonNeutron(bool proton, float length, float posx, float posy, float posz){

    // Proton or Neutron
    if (proton) {
        glColor3f(1.0, 0.0, 0.0);
    } else {
        glColor3f(0.0, 0.0, 1.0);
    }

    glPushMatrix();
    glTranslatef(posx, posy, posz);
    glutSolidSphere(length, 30.0, 30.0 );
    glPopMatrix();
}

void drawSolarSystem(){

    float dist = 0.15;
    float increment = 0.13;

    // Core -------------------------------------------

    float pn = 0.025;

    drawProtonNeutron(true, pn, 0.04, 0.0, 0.04);
    drawProtonNeutron(false, pn, -0.04, 0.0, -0.04);
    drawProtonNeutron(true, pn, -0.04, 0.0, 0.04);
    drawProtonNeutron(false, pn, 0.04, 0.0, -0.04);

    drawProtonNeutron(false, pn, 0.02, 0.02, 0.02);
    drawProtonNeutron(true, pn, -0.02, 0.02, 0.02);
    drawProtonNeutron(false, pn, 0.02, -0.02, 0.02);
    drawProtonNeutron(true, pn, 0.02, 0.02, -0.02);
    drawProtonNeutron(false, pn, -0.02, -0.02, 0.02);
    drawProtonNeutron(true, pn, 0.02, -0.02, -0.02);
    drawProtonNeutron(false, pn, -0.02, 0.02, -0.02);
    drawProtonNeutron(true, pn, -0.02, -0.02, -0.02);

    float len = 0.02;

    // Layer 1 -------------------------------------------

    drawElectron(dist, len, 22.0);
    drawElectron(dist, len, 202.0);

    // Layer 2 -------------------------------------------

    dist += increment;
    float angle = 45;
    for(int i = 0; i < 8; i++){
        drawElectron(dist, len, angle);
        angle += 45;
    }

    // Layer 3 -------------------------------------------

    dist += increment;
    drawElectron(dist, len, 112.0);
    drawElectron(dist, len, 292.0);
}

void display(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
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
    gluPerspective(15.0, (GLfloat)height / (GLfloat)width, 1.0, 128.0);
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
	glutCreateWindow("Atom");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
