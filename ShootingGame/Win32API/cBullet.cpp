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
	playerBullet.ShootDelay = 0;
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

	for (auto iter = m_vecEnemyBullets.begin(); iter != m_vecEnemyBullets.end();)
	{
			iter->x += cosf(iter->angle / 180 * PI) * iter->speed;
			iter->y += -sinf(iter->angle / 180 * PI) * iter->speed;

			RECT rt;
			iter->rtEnemyBullet = RectMakeCenter( (int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2 );
			if (IntersectRect(&rt, &m_pPlayer->GetCollisionNomal(), &iter->rtEnemyBullet))
			{
				iter= m_vecEnemyBullets.erase(iter);
			}
			else if (IntersectRect(&rt, &m_pPlayer->GetCollisionLeft(), &iter->rtEnemyBullet))
			{
				iter = m_vecEnemyBullets.erase(iter);
			}
			else if (IntersectRect(&rt, &m_pPlayer->GetCollisionRight(), &iter->rtEnemyBullet))
			{
				iter = m_vecEnemyBullets.erase(iter);
			}
			else
			{
				iter++;
			}
	}

	if (m_pPlayer->GetIsShoot() == true)
	{
		if (playerBullet.ShootDelay > 0)
		{
 			--playerBullet.ShootDelay;
		}
		if (playerBullet.ShootDelay == 0)
		{
			playerBullet.ShootDelay = 10;

			playerBullet.x = m_pPlayer->GetPosX();
			playerBullet.y = m_pPlayer->GetPosY();
			playerBullet.y1 = m_pPlayer->GetPosY();
			playerBullet.speed = 5;
			playerBullet.radius = 3;
			playerBullet.angle = GetAngle(playerBullet.x, playerBullet.y, m_pEnemy->GetPosX(), m_pEnemy->GetPosY());

			m_vecPlayerBullets.push_back(playerBullet);
		}
	}
	else
	{
		playerBullet.ShootDelay = 0;
	}

	for (auto iter = m_vecPlayerBullets.begin(); iter != m_vecPlayerBullets.end();)
	{
		if (m_pPlayer->GetPosY() < m_pEnemy->GetPosY())
		{
			iter->x += cosf(iter->angle / 180 * PI) * iter->speed;
			iter->y += -sinf(iter->angle / 180 * PI) * iter->speed;
		}
		else
		{
			iter->y -= iter->speed;
		}

		RECT rt1;
		iter->rtPlayerBullet = RectMakeCenter((int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
		if ((IntersectRect(&rt1, &m_pEnemy->GetBoundingBox() , &iter->rtPlayerBullet)) || iter->y < 0 )
		{
			iter = m_vecPlayerBullets.erase(iter);
		}
		else
		{
			iter++;
		}
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

	HPEN hPen1 = (HPEN)CreatePen(0, 1, RGB(0, 0, 255));
	HPEN hSelectPen1 = (HPEN)SelectObject(g_hDC, hPen1);

	for (auto iter = m_vecPlayerBullets.begin(); iter != m_vecPlayerBullets.end(); iter++)
	{
		EllipseMakeCenter(g_hDC, (int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
	}

	DeleteObject(hSelectPen1);
	DeleteObject(hPen1);
}

