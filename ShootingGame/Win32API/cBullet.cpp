#include "stdafx.h"
#include "cBullet.h"
#include "cEnemy.h"
#include "cPlayer.h"

cBullet::cBullet()
{
}

cBullet::~cBullet()
{
}

void cBullet::Setup()
{
	enemyBullet.ShootDelay = 0;
}

void cBullet::Update()
{	
	if (enemyBullet.ShootDelay > 0)
		{
			--enemyBullet.ShootDelay;
		}
		if (enemyBullet.ShootDelay == 0)
		{
			enemyBullet.ShootDelay = 20;

			enemyBullet.x = m_pEnemy->GetPosX();
			enemyBullet.y = m_pEnemy->GetPosY();
			enemyBullet.speed = 5;
			enemyBullet.radius = 3;
			enemyBullet.angle = GetAngle(enemyBullet.x, enemyBullet.y, m_pPlayer->GetPosX(), m_pPlayer->GetPosY());

			m_vecEnemyBullets.push_back(enemyBullet);
		}

	for (auto iter = m_vecEnemyBullets.begin(); iter != m_vecEnemyBullets.end(); iter++)
	{
			iter->x += cosf(iter->angle / 180 * PI) * iter->speed;
			iter->y += -sinf(iter->angle / 180 * PI) * iter->speed;

			iter->rtEnemyBullet = { (int)iter->x, (int)iter->y, (int)iter->x, (int)iter->y};
	}
	
}

void cBullet::Render()
{
	HPEN hPen = (HPEN)CreatePen(0, 3, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	for (auto iter = m_vecEnemyBullets.begin(); iter != m_vecEnemyBullets.end(); iter++)
	{
		EllipseMakeCenter(g_hDC, (int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
	}

	DeleteObject(hSelectPen);
	DeleteObject(hPen);
}

