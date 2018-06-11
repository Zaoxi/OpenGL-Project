#include "DrawingManager.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

void DisplayFunc()
{
	DrawingManager::GetInstance()->GetDrawingObject()->MyDisplayFunc();
}
void ReshapeFunc(int w, int h)
{
	DrawingManager::GetInstance()->GetViewController()->ReshapeFunc(w, h);
}
void KeyboardFunc(unsigned char key, int x, int y)
{
	DrawingManager::GetInstance()->GetViewController()->KeyboardFunc(key, x, y);
}
void MousePassiveFunc(int x, int y)
{
	//DrawingManager::GetInstance()->GetViewController()->MousePassiveFunc(x, y);
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("My Project");

	glutDisplayFunc(DisplayFunc);
	glutKeyboardFunc(KeyboardFunc);
	glutReshapeFunc(ReshapeFunc);
	glutPassiveMotionFunc(MousePassiveFunc);
	glutMainLoop();
	return 0;
}