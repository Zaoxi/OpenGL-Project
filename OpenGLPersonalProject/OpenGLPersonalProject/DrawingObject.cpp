
#include "DrawingManager.h"

// Object, Lighting, Texture 등 초기화
DrawingObject::DrawingObject()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//glDepthMask(GL_TRUE);

	// For Creating texture Objects
	makeFloorImage(floorImage);
	makeCeilImage(ceilImage);
	makeWallSideImage(wallSideImage);
	makeWallFrontBackImage(wallFrontBackImage);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &floorTex);
	glBindTexture(GL_TEXTURE_2D, floorTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FLOOR_WIDTH, FLOOR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, floorImage);

	glGenTextures(1, &ceilTex);
	glBindTexture(GL_TEXTURE_2D, ceilTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, FLOOR_WIDTH, FLOOR_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, ceilImage);

	glGenTextures(1, &wallSideTex);
	glBindTexture(GL_TEXTURE_2D, wallSideTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WALL_SIDE_WIDTH, WALL_SIDE_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, wallSideImage);

	glGenTextures(1, &wallFrontBackTex);
	glBindTexture(GL_TEXTURE_2D, wallFrontBackTex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); // maximum
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // minimum
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL/**/);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WALL_FRONT_BACK_WIDTH, WALL_FRONT_BACK_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, wallFrontBackImage);


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
			image[i][j][3] = (GLubyte)255;
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
			image[i][j][3] = (GLubyte)255;
		}
	}
}

void DrawingObject::makeWallSideImage(GLubyte image[][WALL_SIDE_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < WALL_SIDE_HEIGHT; i++) {
		for (j = 0; j < WALL_SIDE_WIDTH; j++) {
			c = 200;

			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)255;
		}
	}
}

void DrawingObject::makeWallFrontBackImage(GLubyte image[][WALL_FRONT_BACK_WIDTH][4])
{
	int i, j, c;

	for (i = 0; i < WALL_FRONT_BACK_HEIGHT; i++) {
		for (j = 0; j < WALL_FRONT_BACK_WIDTH; j++) {
			c = 150;

			image[i][j][0] = (GLubyte)c;
			image[i][j][1] = (GLubyte)c;
			image[i][j][2] = (GLubyte)c;
			image[i][j][3] = (GLubyte)255;
		}
	}
}

// glutDisplayFunc()의 패러미터메소드
void DrawingObject::MyDisplayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawingManager::GetInstance()->GetViewController()->SetView();
	drawLight();
	drawRoom();
	//drawDesk();
	//drawChair();
	//drawScreen();
	//drawWindow();
	//drawBoard();
	//drawDoor();
}

void DrawingObject::drawLight()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 빛의 위치 설정
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, lightDirection);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, lightSpotAngle);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0f);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection);
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, lightSpotAngle);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0f);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void DrawingObject::drawRoom()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0, 1.0, 1.0);
	
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
	
	glutSwapBuffers();
}