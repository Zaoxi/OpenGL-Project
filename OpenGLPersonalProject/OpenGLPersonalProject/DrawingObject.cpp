
#include "DrawingManager.h"
#include <iostream>
using namespace std;
// Object, Lighting, Texture 등 초기화
DrawingObject::DrawingObject()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	//glDepthMask(GL_TRUE);

	// For Creating texture Objects
	makeFloorImage(floorImage);
	makeCeilImage(ceilImage);
	makeWallSideImage(wallSideImage);
	makeWallFrontBackImage(wallFrontBackImage);
	makeDeskImage(deskImage);
	makeBoardImage(boardImage);
	makeWindowImage(windowImage);
	makeScreenImage(screenImage);
	makeDoorImage(doorImage);
	makeBackStandImage(standImage);
	makeBlackImage(blackImage);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &floorTex);
	glBindTexture(GL_TEXTURE_2D, floorTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FLOOR_WIDTH, FLOOR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, floorImage);

	glGenTextures(1, &ceilTex);
	glBindTexture(GL_TEXTURE_2D, ceilTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FLOOR_WIDTH, FLOOR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, ceilImage);

	glGenTextures(1, &wallSideTex);
	glBindTexture(GL_TEXTURE_2D, wallSideTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WALL_SIDE_WIDTH, WALL_SIDE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, wallSideImage);

	glGenTextures(1, &wallFrontBackTex);
	glBindTexture(GL_TEXTURE_2D, wallFrontBackTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WALL_FRONT_BACK_WIDTH, WALL_FRONT_BACK_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, wallFrontBackImage);

	glGenTextures(1, &deskTex);
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, DESK_WIDTH, DESK_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, deskImage);

	glGenTextures(1, &boardTex);
	glBindTexture(GL_TEXTURE_2D, boardTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, BOARD_WIDTH, BOARD_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, boardImage);

	glGenTextures(1, &windowTex);
	glBindTexture(GL_TEXTURE_2D, windowTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WINDOW_WIDTH, WINDOW_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, windowImage);

	glGenTextures(1, &screenTex);
	glBindTexture(GL_TEXTURE_2D, screenTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, screenImage);

	glGenTextures(1, &doorTex);
	glBindTexture(GL_TEXTURE_2D, doorTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, DOOR_WIDTH, DOOR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, doorImage);

	glGenTextures(1, &standTex);
	glBindTexture(GL_TEXTURE_2D, standTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, STAND_WIDTH, STAND_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, standImage);
	
	glGenTextures(1, &blackTex);
	glBindTexture(GL_TEXTURE_2D, blackTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, BLACK_WIDTH, BLACK_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, blackImage);
}

void DrawingObject::makeFloorImage(GLubyte image[][FLOOR_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < FLOOR_HEIGHT; i++) {
		for (j = 0; j < FLOOR_WIDTH; j++) {
			if (i % 40 == 0 || j % 40 == 0)
			{
				c = 100;
			}
			else
			{
				c = rand() % 55 + 200;
			}
			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeCeilImage(GLubyte image[][FLOOR_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < FLOOR_HEIGHT; i++) {
		for (j = 0; j < FLOOR_WIDTH; j++) {
			c = rand() % 55 + 200;

			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeWallSideImage(GLubyte image[][WALL_SIDE_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < WALL_SIDE_HEIGHT; i++) {
		for (j = 0; j < WALL_SIDE_WIDTH; j++) {
			if (i < 100)
			{
				c = 0;
			}
			else
			{
				c = 200;
			}
			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeWallFrontBackImage(GLubyte image[][WALL_FRONT_BACK_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < WALL_FRONT_BACK_HEIGHT; i++) {
		for (j = 0; j < WALL_FRONT_BACK_WIDTH; j++) {
			if (i < 25)
			{
				c = 0;
			}
			else
			{
				c = 150;
			}

			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeBoardImage(GLubyte image[][BOARD_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < BOARD_HEIGHT; i++) {
		for (j = 0; j < BOARD_WIDTH; j++) {
			if (i < 1 || i > BOARD_HEIGHT - 2 || j < 2 || j > BOARD_WIDTH - 3)
			{
				c = 96;
			}
			else
			{
				c = 255;
			}

			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeDeskImage(GLubyte image[][DESK_WIDTH][4])
{
	int i, j, c;

	int brown[11][3] = { {163, 92, 22},
	{122, 69, 16},
	{135, 69, 2} ,
	{255, 145, 36},
	{ 255, 145, 36 },
	{255, 181, 108},
	{ 255, 181, 108 },
	{ 255, 145, 36 },
	{ 255, 145, 36 },
	{ 255, 181, 108 },
	{ 255, 181, 108 } };

	int color[8][3] = 
	{
	{230, 230, 230},
	{150, 150, 150},
	{160, 160, 160},
	{170, 170, 170},
	{180, 180, 180},
	{190, 190, 190},
	{190, 190, 190},
	{230, 230, 230}
	};

	for (i = 0; i < DESK_HEIGHT; i++) {
		for (j = 0; j < DESK_WIDTH; j++) {
			c = rand() % 8;
			image[i][j][0] = (GLubyte)color[c][0];
			image[i][j][1] = (GLubyte)color[c][1];
			image[i][j][2] = (GLubyte)color[c][2];
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeWindowImage(GLubyte image[][WINDOW_WIDTH][4])
{
	int i, j;
	GLubyte color[3];

	for (i = 0; i < WINDOW_HEIGHT; i++) {
		for (j = 0; j < WINDOW_WIDTH; j++) {
			// 하늘색 배경
			color[0] = (GLubyte)0;
			color[1] = (GLubyte)128;
			color[2] = (GLubyte)255;
			// 나무 줄기
			if (i < WINDOW_HEIGHT / 2 - 9 && j > WINDOW_WIDTH / 2 - 2 && j < WINDOW_WIDTH / 2 + 2)
			{
				color[0] = (GLubyte)162;
				color[1] = (GLubyte)70;
				color[2] = (GLubyte)0;
			} // 나뭇잎
			else if (i > WINDOW_HEIGHT / 2 - 10 && i < WINDOW_HEIGHT / 2 + 14)
			{
				color[0] = (GLubyte)0;
				color[1] = (GLubyte)196;
				color[2] = (GLubyte)52;
			} // 철창살
			if (i < 2 || i > WINDOW_HEIGHT - 3 || j < 2 || j > WINDOW_WIDTH - 3 || j % 6 < 3)
			{
				color[0] = (GLubyte)96;
				color[1] = (GLubyte)96;
				color[2] = (GLubyte)96;
			}

			image[i][j][0] = (GLubyte)color[0];
			image[i][j][1] = (GLubyte)color[1];
			image[i][j][2] = (GLubyte)color[2];
			image[i][j][3] = (GLubyte)255;
		}
	}
}

void DrawingObject::makeScreenImage(GLubyte image[][SCREEN_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < SCREEN_HEIGHT; i++) {
		for (j = 0; j < SCREEN_WIDTH; j++) {
			c = 210;

			if (i > 9 && i < SCREEN_HEIGHT - 10 && j > 5 && j < SCREEN_WIDTH - 6)
			{
				c = rand() % 255;
			}
			else if (i < 3)
			{
				c = 85;
			}
			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)255;
		}
	}
}

void DrawingObject::makeDoorImage(GLubyte image[][DOOR_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < DOOR_HEIGHT; i++) {
		for (j = 0; j < DOOR_WIDTH; j++) {
			c = 120;

			if (i == DOOR_HEIGHT / 2 && j < DOOR_WIDTH - 1 && j > DOOR_WIDTH / 2 + 1)
			{
				c = 40;
			}
			
			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeBackStandImage(GLubyte image[][STAND_WIDTH][4])
{
	int i, j;
	GLubyte color[3] = { 0 };

	for (i = 0; i < STAND_HEIGHT; i++) {
		for (j = 0; j < STAND_WIDTH; j++) {
			if (i < 1 || i > STAND_HEIGHT - 2 || j < 2 || j > STAND_WIDTH - 3)
			{
				color[0] = 210;
				color[1] = 210;
				color[2] = 210;
			}
			else
			{
				color[0] = 0;
				color[1] = 200;
				color[2] = 240;
			}
			

			image[i][j][0] = (GLubyte)color[0];
			image[i][j][1] = (GLubyte)color[1];
			image[i][j][2] = (GLubyte)color[2];
			image[i][j][3] = (GLubyte)30;
		}
	}
}

void DrawingObject::makeBlackImage(GLubyte image[][BLACK_WIDTH][4])
{
	int i, j;

	for (i = 0; i < BLACK_HEIGHT; i++) {
		for (j = 0; j < BLACK_WIDTH; j++) {
			image[i][j][0] = 0;
			image[i][j][1] = 0;
			image[i][j][2] = 0;
			image[i][j][3] = 255;
		}
	}
}

void DrawingObject::MyAnimation()
{
	// 스크린 노이즈 애니메이션
	makeScreenImage(screenImage);
	glGenTextures(1, &screenTex);
	glBindTexture(GL_TEXTURE_2D, screenTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, screenImage);


}

// glutDisplayFunc()의 패러미터메소드
void DrawingObject::MyDisplayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawingManager::GetInstance()->GetViewController()->SetView();
	drawRoom();
	drawArrangedDesk();
	drawBoard();
	drawArrangedWindow();
	drawArrangedChair();
	drawScreen();
	drawDoor();
	drawProjector();
	drawArrangedMonitor();
	drawBackStand();
	drawProf();

	glutSwapBuffers();
}

void DrawingObject::drawBackStand()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 0.0f, 0.0f);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, standTex);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(40.0f, -20.0f, -70.0f);
	glTexCoord2d(1, 0); glVertex3f(10.0f, -20.0f, -70.0f);
	glTexCoord2d(1, 1); glVertex3f(10.0f, -5.0f, -70.0f);
	glTexCoord2d(0, 1); glVertex3f(40.0f, -5.0f, -70.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawingObject::drawProjector()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.0f, 15.0f, 15.0f);
	glutSolidCube(2.0f);
}

void DrawingObject::drawScreen()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, screenTex);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(-15.0f, -15.0f, 78.0f);
	glTexCoord2d(1, 0); glVertex3f(15.0f, -15.0f, 78.0f);
	glTexCoord2d(1, 1); glVertex3f(15.0f, 20.0f, 78.0f);
	glTexCoord2d(0, 1); glVertex3f(-15.0f, 20.0f, 78.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawingObject::drawDoor()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, doorTex);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(-39.9f, -20.0f, -75.0f);
	glTexCoord2d(1, 0); glVertex3f(-39.9f, -20.0f, -65.0f);
	glTexCoord2d(1, 1); glVertex3f(-39.9f, 10.0f, -65.0f);
	glTexCoord2d(0, 1); glVertex3f(-39.9f, 10.0f, -75.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(-39.9f, -20.0f, 65.0f);
	glTexCoord2d(1, 0); glVertex3f(-39.9f, -20.0f, 75.0f);
	glTexCoord2d(1, 1); glVertex3f(-39.9f, 10.0f, 75.0f);
	glTexCoord2d(0, 1); glVertex3f(-39.9f, 10.0f, 65.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawingObject::arrangeChair()
{
	glPushMatrix();
	glScalef(2.0f, 2.0f, 2.0f);
	drawChair();
	glPopMatrix();
	glPushMatrix();

	glTranslatef(-10.0f, 0.0f, 0.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	drawChair();
	glPopMatrix();

	for (int i = 0; i < 8; i++)
	{
		glTranslatef(0.0f, 0.0f, -15.0f);
		glPushMatrix();
		glScalef(2.0f, 2.0f, 2.0f);
		drawChair();
		glPopMatrix();
		glPushMatrix();

		glTranslatef(-10.0f, 0.0f, 0.0f);
		glScalef(2.0f, 2.0f, 2.0f);
		drawChair();
		glPopMatrix();
	}
}

void DrawingObject::drawArrangedChair()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	// 왼쪽줄
	glTranslatef(30.0f, -15.0f, 60.0f);
	arrangeChair();

	// 중간줄
	glLoadIdentity();

	glTranslatef(5.0f, -15.0f, 60.0f);
	arrangeChair();
	// 오른쪽 줄
	glLoadIdentity();

	glTranslatef(-20.0f, -15.0f, 60.0f);
	arrangeChair();

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(25.0f, -15.0f, 70.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawChair();

	glPopMatrix();
}

void DrawingObject::drawChair()
{	
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glEnd();
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -2.0f, 0.0f);

	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(1.0f, -2.2f, 1.0f);

	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(-1.0f, -2.2f, 1.0f);

	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(1.0f, -2.2f, -1.0f);

	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(-1.0f, -2.2f, -1.0f);
	glEnd();
}

void DrawingObject::drawArrangedWindow()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(39.0f, 0.0f, 70.0f);
	glPushMatrix();

	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	drawWindow();

	glPopMatrix();

	for (int i = 0; i < 7; i++)
	{
		glTranslatef(0.0f, 0.0f, -20.0f);
		glPushMatrix();

		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		drawWindow();
		glPopMatrix();
	}
}

void DrawingObject::drawWindow()
{
	//glColor3f(0.0f, 0.5f, 1.0f);
	//glBegin(GL_QUADS);
	//glVertex3f(-1.0f, 1.5f, 0.0f);
	//glVertex3f(-1.0f, -1.5f, 0.0f);
	//glVertex3f(1.0f, -1.5f, 0.0f);
	//glVertex3f(1.0f, 1.5f, 0.0f);
	//glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, windowTex);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 1); glVertex3f(-5.0f, 7.5f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(-5.0f, -7.5f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(5.0f, -7.5f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(5.0f, 7.5f, 0.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void DrawingObject::arrangeDesk()
{
	glPushMatrix();
	drawDesk();

	glTranslatef(-10.0f, 0.0f, 0.0f);
	drawDesk();
	glPopMatrix();

	for (int i = 0; i < 8; i++)
	{
		// 다음줄
		glTranslatef(0.0f, 0.0f, -15.0f);
		glPushMatrix();
		drawDesk();

		glTranslatef(-10.0f, 0.0f, 0.0f);
		drawDesk();
		glPopMatrix();
	}
	glPopMatrix();
}

void DrawingObject::drawArrangedDesk()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	// 첫번째 왼쪽줄
	glTranslatef(30.0f, -20.0f, 60.0f);
	arrangeDesk();

	glLoadIdentity();
	// 첫번째 가운데 줄
	glTranslatef(5.0f, -20.0f, 60.0f);
	arrangeDesk();

	glLoadIdentity();
	// 첫번째 오른쪽 줄??
	glTranslatef(-20.0f, -20.0f, 60.0f);
	arrangeDesk();
	
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(25.0f, -20.0f, 70.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawDesk();

	glPopMatrix();	
}

void DrawingObject::drawArrangedMonitor()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	glTranslatef(28.0f, -15.0f, 73.0f);
	arrangeMonitor();

	glLoadIdentity();
	glTranslatef(3.0f, -15.0f, 73.0f);
	arrangeMonitor();

	glLoadIdentity();
	glTranslatef(-23.0f, -15.0f, 73.0f);
	arrangeMonitor();

	glLoadIdentity();
	glTranslatef(27.0f, -15.0f, 56.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	drawMonitor();

	glPopMatrix();
}

void DrawingObject::arrangeMonitor()
{
	glPushMatrix();
	drawMonitor();

	glTranslatef(-10.0f, 0.0f, 0.0f);
	drawMonitor();
	glPopMatrix();

	for (int i = 0; i < 8; i++)
	{
		// 다음줄
		glTranslatef(0.0f, 0.0f, -15.0f);
		glPushMatrix();
		drawMonitor();

		glTranslatef(-10.0f, 0.0f, 0.0f);
		drawMonitor();
		glPopMatrix();
	}
	glPopMatrix();
}

void DrawingObject::drawMonitor()
{
	GLUquadricObj  *qobj;

	qobj = gluNewQuadric(); //  Quadric 객체 속성 설정 함수
	gluQuadricDrawStyle(qobj, GLU_FILL); // 포인터랑 속성을 설정해줄 인자를 넘긴다.
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, screenTex);

	glBegin(GL_QUADS);
	// 화면부분
	glTexCoord2d(0, 1); glVertex3f(0.0f, 5.0f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(5.0f, 5.0f, 0.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, blackTex);

	glBegin(GL_QUADS);
	// 왼쪽면
	glTexCoord2d(0, 1); glVertex3f(0.0f, 5.0f, 0.5f);
	glTexCoord2d(0, 0); glVertex3f(0.0f, 0.0f, 0.5f);
	glTexCoord2d(1, 0); glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(0.0f, 5.0f, 0.0f);
	// 윗면
	glTexCoord2d(0, 1); glVertex3f(5.0f, 5.0f, 0.5f);
	glTexCoord2d(0, 0); glVertex3f(0.0f, 5.0f, 0.5f);
	glTexCoord2d(1, 0); glVertex3f(0.0f, 5.0f, 0.0f);
	glTexCoord2d(1, 1); glVertex3f(5.0f, 5.0f, 0.0f);
	// 오른쪽면
	glTexCoord2d(0, 1); glVertex3f(5.0f, 5.0f, 0.0f);
	glTexCoord2d(0, 0); glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2d(1, 0); glVertex3f(5.0f, 0.0f, 0.5f);
	glTexCoord2d(1, 1); glVertex3f(5.0f, 5.0f, 0.5f);
	// 뒷면
	glTexCoord2d(0, 1); glVertex3f(0.0f, 5.0f, 0.5f);
	glTexCoord2d(0, 0); glVertex3f(0.0f, 0.0f, 0.5f);
	glTexCoord2d(1, 0); glVertex3f(5.0f, 0.0f, 0.5f);
	glTexCoord2d(1, 1); glVertex3f(5.0f, 5.0f, 0.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3f(0.9f, 0.9f, 0.9f);
	glTranslatef(2.5f, 1.0f, 0.5f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.5, 0.5, 1.5, 20, 10);
	glPopMatrix();
}

void DrawingObject::drawBoard()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(0.0f, 0.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, boardTex);

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3f(-25.0f, -10.0f, 79.0f);
	glTexCoord2d(1, 0); glVertex3f(25.0f, -10.0f, 79.0f);
	glTexCoord2d(1, 1); glVertex3f(25.0f, 10.0f, 79.0f);
	glTexCoord2d(0, 1); glVertex3f(-25.0f, 10.0f, 79.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

void DrawingObject::drawDesk()
{

	glColor3f(0.0f, 0.0f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, deskTex);
	glBegin(GL_QUADS);
	// 책상 윗면
	glTexCoord2d(0.0, 1.0); glVertex3f(-5.0f, 5.0f, 5.0f);
	glTexCoord2d(0.0, 0.0); glVertex3f(-5.0f, 5.0f, 0.0f);
	glTexCoord2d(1.0, 0.0); glVertex3f(5.0f, 5.0f, 0.0f);
	glTexCoord2d(1.0, 1.0); glVertex3f(5.0f, 5.0f, 5.0f);

	//책상 다리
	glTexCoord2d(0.0, 1.0); glVertex3f(-5.0f, 5.0f, 5.0f);
	glTexCoord2d(0.0, 0.0); glVertex3f(-5.0f, 5.0f, 0.0f);
	glTexCoord2d(1.0, 0.0); glVertex3f(-5.0f, 0.0f, 0.0f);
	glTexCoord2d(1.0, 1.0); glVertex3f(-5.0f, 0.0f, 5.0f);

	glTexCoord2d(0.0, 1.0); glVertex3f(5.0f, 5.0f, 5.0f);
	glTexCoord2d(0.0, 0.0); glVertex3f(5.0f, 5.0f, 0.0f);
	glTexCoord2d(1.0, 0.0); glVertex3f(5.0f, 0.0f, 0.0f);
	glTexCoord2d(1.0, 1.0); glVertex3f(5.0f, 0.0f, 5.0f);

	// 책상 뒷면
	glTexCoord2d(0.0, 1.0); glVertex3f(-5.0f, 5.0f, 5.0f);
	glTexCoord2d(0.0, 0.0); glVertex3f(5.0f, 5.0f, 5.0f);
	glTexCoord2d(1.0, 0.0); glVertex3f(5.0f, 0.0f, 5.0f);
	glTexCoord2d(1.0, 1.0); glVertex3f(-5.0f, 0.0f, 5.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void DrawingObject::drawRoom()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(0.0f, 0.0f, 0.0f);

	glPushMatrix();


	// 앞면
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wallFrontBackTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽아래
	glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽위
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽위
	// 뒷면
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽위
	glTexCoord2f(0.0f, 1.0f); glVertex3f(40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽위
	glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽아래
	glEnd();

	// 오른면

	glBindTexture(GL_TEXTURE_2D, wallSideTex);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽위
	glTexCoord2f(0.0f, 1.0f); glVertex3f(40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽위
	glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽아래
	// 왼면
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽아래
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽위
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽위
	glEnd();


	// 윗면
	glBindTexture(GL_TEXTURE_2D, ceilTex);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽위
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽아래
	glTexCoord2f(1.0f, 0.0f); glVertex3f(40.0f, 20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glTexCoord2f(1.0f, 1.0f); glVertex3f(40.0f, 20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽위
	glEnd();
	// 아랫면
	glBindTexture(GL_TEXTURE_2D, floorTex);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 오른쪽위
	glTexCoord2f(0.0f, 1.0f); glVertex3f(40.0f, -20.0f, -80.0f);    // 텍스처와 쿼드의 왼쪽위
	glTexCoord2f(0.0f, 0.0f); glVertex3f(40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 왼쪽아래
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-40.0f, -20.0f, 80.0f);    // 텍스처와 쿼드의 오른쪽아래
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}



void DrawingObject::drawProf()
{
	GLUquadricObj  *qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0.0f, -11.0f, 0.0f);
	glPushMatrix();
	// 얼굴, 몸
	glutSolidSphere(1.0f, 50, 50);
	glTranslatef(0.0f, -1.0f, 0.0f);
	glPushMatrix();
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.5, 0.5, 4.0, 20, 5);
	glPopMatrix();
	// 왼팔
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(70.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.3, 0.3, 4.0, 20, 5);
	glPopMatrix();
	// 오른팔
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(110.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.3, 0.3, 4.0, 20, 5);
	glPopMatrix();

	glTranslatef(0.05, -4.0f, 0.0f);
	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(80.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.3, 0.3, 4.0, 20, 5);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(100.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(qobj, 0.3, 0.3, 4.0, 20, 5);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}