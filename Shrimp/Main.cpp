#define _CRT_SECURE_NO_DEPRECATE

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "ImageLoader.h"
#include "ShrimpModel.h"

// angle of rotation for the camera direction
float angleX = 0.0f;
float angleY = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, ly = 0.0f;

// XZ position of the camera
float x = 0.0f, z = 5.0f, y = 2.0f;

// the key states. These variables will be zero
//when no key is being presses
float deltaXAngle = 0.0f;
float deltaYAngle = 0.0f;
float deltaMove = 0;
float deltaSideMove = 0;
int xOrigin = -1;
int yOrigin = -1;

static double yVal = 1.0;

void init(double a, double b, double c, double d, double e, double f)
{
	GLfloat mat_specular[] = { 0.3, 1.0, 0.3, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { a, b, c, 1.0 };
	GLfloat spotDir[] = { d, e, f };
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// Definig spotlight attributes
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 95.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) 
{
	x += (deltaMove * lx - deltaSideMove * lz) * 0.1f;
	z += (deltaMove * lz + deltaSideMove * lx) * 0.1f;
	y += deltaMove * ly * 0.1f;
}

void renderScene(void)
{
	if (deltaMove || deltaSideMove)
		computePos(deltaMove);

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	init(yVal, 5.0, 1.5, 10.0, 1.0, 10.0);

	// Set the camera
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);



	glPushMatrix();
		glutSolidSphere(0.3, 30, 30);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.1f, 0.0f, 0.3f);
		glTranslatef(0.0f, -6.0f, 0.0f);
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = -50; i < 50; i++)
		{
			for (int j = -50; j < 50; j++)
			{
				glVertex3f(i, 0.0f, j);
				glVertex3f(i + 1, 0.0f, j);
			}
		}
		glEnd();
	glPopMatrix();
	// Draw 4 shrimps

	for (int i = -1; i < 1; i++)
	for (int j = -1; j < 1; j++) {
		glPushMatrix();
		glTranslatef(i*10.0, 0, j * 10.0);
		glColor3f(1.0f, 0.0f, 0.0f);
		drawShrimp();
		glPopMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int xx, int yy) {

	switch (key)
	{
		case 27:
			exit(0);
			break;
		case 'w':
			deltaMove = 0.5f;
			break;
		case 's':
			deltaMove = -0.5f;
			break;
		case 'a':
			deltaSideMove = -0.5f;
			break;
		case 'd':
			deltaSideMove = 0.5f;
			break;
		case  'z':
			yVal > -10 ? yVal-- : yVal;
			printf("Light intensity: %f\n", yVal);
			break;
		case 'c':
			yVal < 10 ? yVal++ : yVal;
			printf("Light intensity: %f\n", yVal);
			break;
	}
}

/*void pressKey(int key, int xx, int yy) {

	switch (key) {
	}
}*/

void releaseKey(unsigned char key, int x, int y) {

	switch (key) {
		case 'w':
		case 's':
			deltaMove = 0;
			break;
		case 'a':
		case 'd':
			deltaSideMove = 0;
			break;
	}
}

void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0 && yOrigin >= 0) {

		// update deltaAngle
		deltaXAngle = (x -  xOrigin) * 0.003f;

		// update camera's direction
		lx = sin(angleX + deltaXAngle);
		lz = -cos(angleX + deltaXAngle);

		deltaYAngle = (y - yOrigin) * 0.003f;

		ly = sin(angleY - deltaYAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angleX += deltaXAngle;
			angleY -= deltaYAngle;
			xOrigin = -1;
			yOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	}
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Lighthouse3D - GLUT Tutorial");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutKeyboardUpFunc(releaseKey);
	//glutSpecialFunc(pressKey);
	//glutSpecialUpFunc(releaseKey);

	// here are the two new functions
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	// OpenGL init
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}