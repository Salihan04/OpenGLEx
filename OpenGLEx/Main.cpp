#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void drawPoints() {
	//Set color in RGB format
	glColor3f(0.0f, 1.0f, 0.0f);

	//Set size of points
	glPointSize(10.0f);

	glBegin(GL_POINTS);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.1f, 0.1f);
	glVertex2f(0.2f, 0.2f);
	glVertex2f(0.3f, 0.3f);
	glVertex2f(0.4f, 0.4f);
	glEnd();
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawPoints();

	glutSwapBuffers();
	glutPostRedisplay();
}

void initialiseGlutCallback() {
	glutDisplayFunc(renderScene);
}

int main(int argc, char **argv) {
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