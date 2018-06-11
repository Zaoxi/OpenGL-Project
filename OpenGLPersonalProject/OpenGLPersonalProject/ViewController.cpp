
#include "DrawingManager.h"
#include <math.h>
#define PI 3.141592

// VCS ÃÊ±âÈ­, keyboard and reshape
ViewController::ViewController()
{
}

void ViewController::ReshapeFunc(int w, int h)
{
	window_width = w;
	window_height = h;
	glViewport(0, 0, window_width, window_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)window_width / (GLfloat)window_height, 1.0, 20.0);
	gluLookAt(0.0, 0.0, 0.0, focusX, focusY, focusZ, 0.0, 1.0, 0.0);
}

void ViewController::SetView()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, (GLfloat)window_width / (GLfloat)window_height, 1.0, 20.0);
	gluLookAt(0.0, 0.0, 0.0, focusX, focusY, focusZ, 0.0, 1.0, 0.0);
}

void ViewController::KeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'r':
		rotation += 10.0f;
		if (rotation > 360.0f)
		{
			rotation -= 360.0f;
		}

		focusX = sinf(rotation * PI / 180.0f);
		focusZ = -cosf(rotation * PI / 180.0f);

		glutPostRedisplay();
		break;
	case 'l':
		rotation -= 10.0f;
		if (rotation < 0.0f)
		{
			rotation += 360.0f;
		}
		glutPostRedisplay();
		break;
	case 'i':
		fov += 1.0f;
		if (fov > 180.0f)
		{
			fov = 180.0f;
		}
		glutPostRedisplay();
		break;
	case 'o':
		fov -= 1.0f;
		if (fov < 0.0f)
		{
			fov = 0.0f;
		}
		glutPostRedisplay();
		break;
	}
}