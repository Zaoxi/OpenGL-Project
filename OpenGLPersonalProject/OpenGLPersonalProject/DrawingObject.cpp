
#include "DrawingManager.h"

// Object, Lighting, Texture �� �ʱ�ȭ
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

// glutDisplayFunc()�� �з����͸޼ҵ�
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

	// ���� ��ġ ����
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
	// �ո�
	glVertex3f(-5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
	glVertex3f(5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
	glVertex3f(5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ ��������
	glVertex3f(-5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ ������
											   // �޸�
	glVertex3f(-5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
	glVertex3f(-5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ��������
	glVertex3f(5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ������
	glVertex3f(5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
										// ����
	glVertex3f(-5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ������
	glVertex3f(-5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
	glVertex3f(5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
	glVertex3f(5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ��������
											// �Ʒ���
	glVertex3f(-5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ ��������
	glVertex3f(5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ ������
	glVertex3f(5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
	glVertex3f(-5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
														// ������
	glVertex3f(5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
	glVertex3f(5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ��������
	glVertex3f(5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ ������
	glVertex3f(5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
											   // �޸�
	glVertex3f(-5.0f, -5.0f, -5.0f);    // �ؽ�ó�� ������ ���ʾƷ�
	glVertex3f(-5.0f, -5.0f, 5.0f);    // �ؽ�ó�� ������ �����ʾƷ�
	glVertex3f(-5.0f, 5.0f, 5.0f);    // �ؽ�ó�� ������ ��������
	glVertex3f(-5.0f, 5.0f, -5.0f);    // �ؽ�ó�� ������ ������
	glEnd();

	glPopMatrix();

	glutSwapBuffers();
}