#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

float random() {
	return (float)(rand() % 1000 - 500) / 500;
}

//Function to draw some points
void drawPoints() {
	//Set color of points in RGB format, default color is white
	glColor3f(0.0f, 1.0f, 0.0f);	//Green

	//Set size of points
	glPointSize(10.0f);

	//Set coordinates of points
	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.4f, 0.4f);
	glEnd();
}

//Function to draw points at random positions with random colors
void drawRandomPoints() {
	//Set color of points in RGB format, default color is white
	glColor3f(random(), random(), random());

	//Set size of points
	glPointSize(10.0f);

	//Set coordinates of points
	glBegin(GL_POINTS);
	for (int i = 0; i < 100; i++) {
		glVertex2f(random(), random());
	}
	glEnd();
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//drawPoints();
	drawRandomPoints();

	glutSwapBuffers();
	glutPostRedisplay();
}

void initialiseGlutCallback() {
	glutDisplayFunc(renderScene);
}

int main(int argc, char **argv) {
	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	//Create window
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Simple OpenGL Exercises");

	initialiseGlutCallback();

	glutMainLoop();

	return 0;
}