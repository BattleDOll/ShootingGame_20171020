#pragma once
#include "cImage.h"

struct tagEnemyBullet
{
	float x, y;				// �Ѿ� �߾� ��ǥ
	float speed;			// �Ѿ� �ӷ�
	float angle;			// �Ѿ� ����
	float radius;			// �Ѿ� ������
};
class cBullet
{
private:
	vector<tagEnemyBullet>				m_vecEnemyBullets;	// �Ѿ� ����

	RECT	rt;

public:
	cBullet();
	~cBullet();
};

