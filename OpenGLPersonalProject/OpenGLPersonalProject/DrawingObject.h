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
#define DESK_WIDTH 64
#define DESK_HEIGHT 32
#define BOARD_WIDTH 80
#define BOARD_HEIGHT 32
#define WINDOW_WIDTH 32
#define WINDOW_HEIGHT 64
#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 64
#define DOOR_WIDTH 16
#define DOOR_HEIGHT 32
#define STAND_WIDTH 32
#define STAND_HEIGHT 16
#define BLACK_WIDTH 2
#define BLACK_HEIGHT 2

class DrawingObject
{
private :
	GLuint floorTex;
	GLuint wallSideTex;
	GLuint wallFrontBackTex;
	GLuint ceilTex;
	GLuint deskTex;
	GLuint boardTex;
	GLuint windowTex;
	GLuint screenTex;
	GLuint doorTex;
	GLuint monitorTex;
	GLuint standTex;
	GLuint blackTex;

	GLubyte floorImage[FLOOR_HEIGHT][FLOOR_WIDTH][4];
	GLubyte wallSideImage[WALL_SIDE_HEIGHT][WALL_SIDE_WIDTH][4];
	GLubyte wallFrontBackImage[WALL_FRONT_BACK_HEIGHT][WALL_FRONT_BACK_WIDTH][4];
	GLubyte ceilImage[FLOOR_HEIGHT][FLOOR_WIDTH][4];
	GLubyte deskImage[DESK_HEIGHT][DESK_WIDTH][4];
	GLubyte boardImage[BOARD_HEIGHT][BOARD_WIDTH][4];
	GLubyte windowImage[WINDOW_HEIGHT][WINDOW_WIDTH][4];
	GLubyte screenImage[SCREEN_HEIGHT][SCREEN_WIDTH][4];
	GLubyte doorImage[DOOR_HEIGHT][DOOR_WIDTH][4];
	GLubyte standImage[STAND_HEIGHT][STAND_WIDTH][4];
	GLubyte blackImage[BLACK_HEIGHT][BLACK_WIDTH][4];

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
	void makeDeskImage(GLubyte image[][DESK_WIDTH][4]);
	void makeBoardImage(GLubyte image[][BOARD_WIDTH][4]);
	void makeWindowImage(GLubyte image[][WINDOW_WIDTH][4]);
	void makeScreenImage(GLubyte image[][SCREEN_WIDTH][4]);
	void makeDoorImage(GLubyte image[][DOOR_WIDTH][4]);
	void makeBackStandImage(GLubyte image[][STAND_WIDTH][4]);
	void makeBlackImage(GLubyte image[][BLACK_WIDTH][4]);

	void drawRoom();
	void drawDesk();
	void drawArrangedDesk();
	void arrangeDesk();
	void drawChair();
	void drawArrangedChair();
	void arrangeChair();
	void drawScreen();
	void drawBoard();
	void drawWindow();
	void drawArrangedWindow();
	void drawDoor();
	void drawProjector();
	void drawMonitor();
	void drawArrangedMonitor();
	void arrangeMonitor();
	void drawBackStand();
	void drawProf();
	void drawMovingProf();
public :
	DrawingObject();

	void MyDisplayFunc();
	void MyAnimation();
};