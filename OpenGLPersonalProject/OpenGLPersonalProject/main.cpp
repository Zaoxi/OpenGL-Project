#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "DrawingManager.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My Project");

	glutDisplayFunc((DrawingManager::GetInstance()->GetDrawingObject())->MyDisplayFunc);
	glutKeyboardFunc((DrawingManager::GetInstance()->GetViewController())->KeyboardFunc);
	glutReshapeFunc((DrawingManager::GetInstance()->GetViewController())->ReshapeFunc);
	glutPassiveMotionFunc((DrawingManager::GetInstance()->GetViewController())->MousePassiveFunc);
	glutMainLoop();
	return 0;
}