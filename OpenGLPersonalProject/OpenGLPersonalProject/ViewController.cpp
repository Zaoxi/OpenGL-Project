
#include "DrawingManager.h"
#include <math.h>
#include <iostream>
#define PI 3.141592f

using namespace std;
// VCS ÃÊ±âÈ­, keyboard and reshape
ViewController::ViewController()
{
	focusX = sinf(rotation * PI / 180.0f);
	focusZ = -cosf(rotation * PI / 180.0f);
}

void ViewController::ReshapeFunc(int w, int h)
{
	window_width = w;
	window_height = h;
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)window_width / (GLfloat)window_height, 1.0, 500.0);
	gluLookAt(positionX, positionY, positionZ, positionX + focusX, positionY + focusY, positionZ + focusZ, 0.0, 1.0, 0.0);
}

void ViewController::SetView()
{
	focusX = sinf(rotation * PI / 180.0f);
	focusZ = -cosf(rotation * PI / 180.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)window_width / (GLfloat)window_height, 1.0, 500.0);
	gluLookAt(positionX, positionY, positionZ, positionX + focusX, positionY + focusY, positionZ + focusZ, 0.0, 1.0, 0.0);
}

void ViewController::KeyboardFunc(unsigned char key, int x, int y)
{
	GLfloat termX, termZ;

	switch (key)
	{
	case 'd': case 'D':
		rotation += 5.0f;
		if (rotation > 360.0f)
		{
			rotation -= 360.0f;
		}

		glutPostRedisplay();
		break;
	case 'a': case 'A':
		rotation -= 5.0f;
		if (rotation < 0.0f)
		{
			rotation += 360.0f;
		}

		glutPostRedisplay();
		break;
	case 'w': case 'W':
		termX = WALK_DISTANCE * sinf(-rotation * PI / 180.0f);
		termZ = WALK_DISTANCE * cosf(-rotation * PI / 180.0f);
		positionX -= termX;
		positionZ -= termZ;
		glutPostRedisplay();
		break;
	case 's': case 'S':
		termX = WALK_DISTANCE * sinf(-rotation * PI / 180.0f);
		termZ = WALK_DISTANCE * cosf(-rotation * PI / 180.0f);
		positionX += termX;
		positionZ += termZ;
		glutPostRedisplay();
	default:
		break;
	}
}