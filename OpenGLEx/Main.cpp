#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

//function to return a random float type random number
float random() {
	return (float)(rand() % 1000 - 500) / 500;
}

//function to draw some points
void drawPoints() {
	//set color of points in RGB format, default color is white
	glColor3f(0.0f, 1.0f, 0.0f);	//Green

	//set size of points
	glPointSize(10.0f);

	//draw points
	glBegin(GL_POINTS);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.1f, 0.1f);
		glVertex2f(0.2f, 0.2f);
		glVertex2f(0.3f, 0.3f);
		glVertex2f(0.4f, 0.4f);
	glEnd();
}

//function to draw points at random positions with random colors
void drawRandomPoints() {
	//set color of points in RGB format, default color is white
	glColor3f(random(), random(), random());

	//set size of points
	glPointSize(10.0f);

	//draw points
	glBegin(GL_POINTS);
	for (int i = 0; i < 100; i++) {
		glVertex2f(random(), random());
	}
	glEnd();
}

//function to draw some lines
void drawLines() {
	//set color of points in RGB format, default color is white
	glColor3f(0.0f, 1.0f, 0.0f);	//Green

	//set size of points
	glPointSize(10.0f);

	//draw points
	glBegin(GL_POINTS);
	glVertex2f(0.5f, 0.0f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.0f, -0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();

	//set color of points in RGB format, default color is white
	glColor3f(1.0f, 0.0f, 0.0f);	//Red

	//set line thickness
	glLineWidth(5.0f);

	//draw lines
	//each pair of points form a line
	glBegin(GL_LINES);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.0f, 0.5f);

		glVertex2f(0.0f, 0.5f);
		glVertex2f(-0.5f, 0.0f);
	
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.0f, -0.5f);
	
		glVertex2f(0.0f, -0.5f);
		glVertex2f(0.5f, 0.0f);
	glEnd();
}

void drawRandomLines() {
	//set color of points in RGB format, default color is white
	glColor3f(random(), random(), random());

	//draw lines
	//each pair of points form a line
	glBegin(GL_LINES);
	for (int i = 0; i < 100; i++) {
		glVertex2f(random(), random());
		glVertex2f(random(), random());
	}
	glEnd();
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	drawPoints();
//	drawRandomPoints();
//	drawLines();
	drawRandomLines();

	glutSwapBuffers();	//to prevent flickering when rendering scene
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