#ifndef OPEN_GL
#define OPEN_GL
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

class DrawingObject
{
private :

	GLuint floorTex;
	GLuint wallTex;
	GLuint ceilTex;
	GLubyte floorImage[TEXTURE_HEIGHT][TEXTURE_WIDTH][4];
	GLubyte wallImage[TEXTURE_HEIGHT][TEXTURE_WIDTH][4];
	GLubyte ceilImage[TEXTURE_HEIGHT][TEXTURE_WIDTH][4];

	GLfloat lightSource_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // opaque
	GLfloat lightSource_emission[4] = { 1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat mat_diffuse[4] = { 0.8f, 0.8f, 0.8f, 0.6f };
	GLfloat mat_emission[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	GLfloat lightPosition[4] = { 4.0f, 4.0f, 0.0f, 1.0f };

	void makeFloorImage(GLubyte image[][TEXTURE_WIDTH][4]);
	void makeWallImage(GLubyte image[][TEXTURE_WIDTH][4]);
	void makeCeilImage(GLubyte image[][TEXTURE_WIDTH][4]);


	void drawRoom();
	void drawLight();
	void drawDesk();
	void drawChair();
	void drawScreen();
	void drawWindow();
	void drawBoard();
	void drawDoor();
public :
	DrawingObject();

	void MyDisplayFunc();

};