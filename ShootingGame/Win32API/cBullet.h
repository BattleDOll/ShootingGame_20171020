#pragma once
#include "cImage.h"

struct tagEnemyBullet
{
	float x, y;				// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥
	float speed;			// ÃÑ¾Ë ¼Ó·Â
	float angle;			// ÃÑ¾Ë ¹æÇâ
	float radius;			// ÃÑ¾Ë ¹ÝÁö¸§
};
class cBullet
{
private:
	vector<tagEnemyBullet>				m_vecEnemyBullets;	// ÃÑ¾Ë º¤ÅÍ

	RECT	rt;

public:
	cBullet();
	~cBullet();
};

