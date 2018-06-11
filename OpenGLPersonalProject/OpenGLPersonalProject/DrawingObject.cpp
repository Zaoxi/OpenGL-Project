
#include "DrawingManager.h"

// Object, Lighting, Texture 등 초기화
DrawingObject::DrawingObject()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glDepthMask(GL_TRUE);

	// For Creating texture Objects
	//makeFloorImage(floorImage);
	//makeWallImage(wallImage);
	//makeCeilImage(ceilImage);

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
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void DrawingObject::drawRoom()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glBegin(GL_QUADS);
	// 앞면
	glVertex3f(-5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽아래
	glVertex3f(5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽아래
	glVertex3f(5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽위
	glVertex3f(-5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽위
											   // 뒷면
	glVertex3f(-5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽아래
	glVertex3f(-5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽위
	glVertex3f(5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽위
	glVertex3f(5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽아래
										// 윗면
	glVertex3f(-5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽위
	glVertex3f(-5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽아래
	glVertex3f(5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽아래
	glVertex3f(5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽위
											// 아랫면
	glVertex3f(-5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽위
	glVertex3f(5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽위
	glVertex3f(5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽아래
	glVertex3f(-5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽아래
														// 오른면
	glVertex3f(5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽아래
	glVertex3f(5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 오른쪽위
	glVertex3f(5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽위
	glVertex3f(5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 왼쪽아래
											   // 왼면
	glVertex3f(-5.0f, -5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽아래
	glVertex3f(-5.0f, -5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽아래
	glVertex3f(-5.0f, 5.0f, 5.0f);    // 텍스처와 쿼드의 오른쪽위
	glVertex3f(-5.0f, 5.0f, -5.0f);    // 텍스처와 쿼드의 왼쪽위
	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}