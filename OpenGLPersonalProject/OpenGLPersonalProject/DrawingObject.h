#ifndef OPEN_GL
#define OPEN_GL
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif
#define FLOOR_WIDTH 800
#define FLOOR_HEIGHT 1600
#define WALL_SIDE_WIDTH 400
#define WALL_SIDE_HEIGHT 1600
#define WALL_FRONT_BACK_WIDTH 800
#define WALL_FRONT_BACK_HEIGHT 400


class DrawingObject
{
private :
	GLuint floorTex;
	GLuint wallSideTex;
	GLuint wallFrontBackTex;
	GLuint ceilTex;
	GLubyte floorImage[FLOOR_HEIGHT][FLOOR_WIDTH][4];
	GLubyte wallSideImage[WALL_SIDE_HEIGHT][WALL_SIDE_WIDTH][4];
	GLubyte wallFrontBackImage[WALL_FRONT_BACK_HEIGHT][WALL_FRONT_BACK_WIDTH][4];
	GLubyte ceilImage[FLOOR_HEIGHT][FLOOR_WIDTH][4];

	GLfloat lightPosition0[4] = { 0.0f, 50.0f, 0.0f, 1.0f };
	GLfloat lightPosition1[4] = { 0.0f, 50.0f, 105.0f, 1.0f };

	GLfloat global_ambient[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
	GLfloat light_diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f }; // opaque
	GLfloat light_ambient[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lightDirection[3] = { 0.0f, -1.0f, 0.0f };
	GLfloat lightSpotAngle[1] = { 90.0f };

	GLfloat mat_diffuse[4] = { 0.25f, 0.25f, 1.0f, 0.0f };
	GLfloat mat_specular[4] = { 1.0f, 1.0f, 1.0f, 0.0f };

	// Method For Making Texture
	void makeFloorImage(GLubyte image[][FLOOR_WIDTH][4]);
	void makeWallSideImage(GLubyte image[][WALL_SIDE_WIDTH][4]);
	void makeWallFrontBackImage(GLubyte image[][WALL_FRONT_BACK_WIDTH][4]);
	void makeCeilImage(GLubyte image[][FLOOR_WIDTH][4]);


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