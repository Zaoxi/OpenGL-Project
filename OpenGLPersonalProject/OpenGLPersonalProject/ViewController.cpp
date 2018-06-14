
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
	lightDirection[0] = focusX;
	lightDirection[2] = focusZ;

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.2f);
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
	lightDirection[0] = focusX;
	lightDirection[2] = focusZ;
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)window_width / (GLfloat)window_height, 1.0, 500.0);
	gluLookAt(positionX, positionY, positionZ, positionX + focusX, positionY + focusY, positionZ + focusZ, 0.0, 1.0, 0.0);
}

void ViewController::KeyboardFunc(unsigned char key, int x, int y)
{
	GLfloat termX, termZ;
	GLfloat newPositionX, newPositionZ;
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
		newPositionX = positionX - termX;
		newPositionZ = positionZ - termZ;
		if (newPositionX <= -37.0f || newPositionX >= 37.0f || newPositionZ <= -77.0f || newPositionZ >= 77.0f)
		{
			break;
		}
		positionX = newPositionX;
		positionZ = newPositionZ;
		lightPosition[0] = newPositionX;
		lightPosition[2] = newPositionZ;
		glutPostRedisplay();
		break;
	case 's': case 'S':
		termX = WALK_DISTANCE * sinf(-rotation * PI / 180.0f);
		termZ = WALK_DISTANCE * cosf(-rotation * PI / 180.0f);
		newPositionX = positionX + termX;
		newPositionZ = positionZ + termZ;
		if (newPositionX <= -37.0f || newPositionX >= 37.0f || newPositionZ <= -77.0f || newPositionZ >= 77.0f)
		{
			break;
		}
		positionX = newPositionX;
		positionZ = newPositionZ;
		lightPosition[0] = newPositionX;
		lightPosition[2] = newPositionZ;
		glutPostRedisplay();
	default:
		break;
	}
}