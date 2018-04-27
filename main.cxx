
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
#include <iostream>
#include "colors.h"
#include "shapes.h"
#include "config.h"
#include "solarsystem.h"

SolarSystem solarsystem;
float
	r = 150,
	teta = 1.5707f,
	px = cos(teta) * r,
	py = 50,
	pz = sin(teta) * r,
	timer = 0;

float pcx = 0, pcy = 0, pcz = 0;

bool play = true;

void keyPressed(unsigned char key, int x, int y) {
	switch(key) {
		case 'a': case 'A':
			teta += 2.0f * RAD;
		break;
		case 'd': case 'D':
			teta -= 2.0f * RAD;
		break;
		case 'w': case 'W':
			r -= 1.0f;
			r = ((r <= 0) ? 0.0001 : r );
		break;
		case 's': case 'S':
			r += 1.0f;
		break;
		case 'e': case 'E':
			py += 1.0f;
		break;
		case 'q': case 'Q':
			py -= 1.0f;
		break;
		case 'p': case 'P':
			play = !play;
		break;
		case '0':
			solarsystem.setPlanetActive(0);
		break;
		case '1':
			solarsystem.setPlanetActive(1);
		break;
		case '2':
			solarsystem.setPlanetActive(2);
		break;
		case '3':
			solarsystem.setPlanetActive(3);
		break;
		case '4':
			solarsystem.setPlanetActive(4);
		break;
		default:
		return;
	}

	px = cos(teta) * r;
	pz = sin(teta) * r;
	glutPostRedisplay();
}

void timeFunc(int value) {
	if(play) timer++;
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timeFunc, value);
}

void myInit (void) {
	HSL(0, 20, 20, true);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearDepth(1.0f);
	glDepthRange(-100.0f, 100.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	solarsystem.addPlanet(2, CUBE,  0.3, 1, 0);
	solarsystem.addPlanet(3, TETRAHEDRON3, -0.3, 1, 0);
	solarsystem.addPlanet(6, TETRAHEDRON4,  0.3, 1, 0);
	solarsystem.addPlanet(8, OCTRAHEDRON, -0.3, 1, 0, 2);
}

void myResize (int w, int h) {
	h = ((h == 0) ? 1 : h );
	float aspect = (GLfloat)w/(GLfloat)h;

	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, aspect, 0.01f, 1000.0f);
}

void myDisplay (void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluLookAt(px, py, pz, pcx, pcy, pcz, 0, 1, 0);

	solarsystem.draw(timer, pcx, pcy, pcz);

	glFlush();
	glutSwapBuffers();
}

int main (int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1400, 800);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Solar System"); 
	myInit();
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myResize);
	glutKeyboardFunc(keyPressed);
	glutTimerFunc(1000 / FPS, timeFunc, 0);
	glutMainLoop();

	return 0;
}