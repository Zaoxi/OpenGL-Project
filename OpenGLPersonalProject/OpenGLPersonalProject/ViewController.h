#ifndef OPEN_GL
#define OPEN_GL
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#define WALK_DISTANCE 0.3f
class ViewController
{
private :
	GLfloat intensity = 0.0f;
	GLfloat lightPosition[4] = { 0.0f, -10.0f, 0.0f, 1.0f };
	GLfloat lightDirection[3] = { 0.0f, -0.5f, 1.0f };
	int window_width = 500, window_height = 500;
	GLfloat rotation = 0.0f;
	GLfloat fov = 100.0f;
	GLfloat focusX = 0.0f, focusY = 0.0f, focusZ = 0.0f;
	GLfloat positionX = 0.0f, positionY = -10.0f, positionZ = 0.0f;
public :
	ViewController();
	void ReshapeFunc(int w, int h);
	void KeyboardFunc(unsigned char key, int x, int y);
	void SetView();
};