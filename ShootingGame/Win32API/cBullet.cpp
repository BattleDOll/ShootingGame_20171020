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
	stEnemyBullet.ShootDelay = 0;
	stPlayerBullet.ShootDelay = 0;
	stPlayerBullet.radius = 3;
}

void cBullet::Update()
{	// Àû ÃÑ¾Ë 
	if (stEnemyBullet.ShootDelay > 0)
	{
		--stEnemyBullet.ShootDelay;
	}
	if (m_pEnemy->GetEnemyHP() >0 && stEnemyBullet.ShootDelay == 0)
	{
		stEnemyBullet.ShootDelay = 20;

		stEnemyBullet.x = m_pEnemy->GetPosX() - 25;
		stEnemyBullet.y = m_pEnemy->GetPosY();
		stEnemyBullet.speed = 5;
		stEnemyBullet.radius = 3;
		stEnemyBullet.Damage = 2;
		stEnemyBullet.angle = GetAngle(stEnemyBullet.x, stEnemyBullet.y, m_pPlayer->GetPosX(), m_pPlayer->GetPosY());

		m_vecEnemyBullets.push_back(stEnemyBullet);

		stEnemyBullet.x = m_pEnemy->GetPosX() + 25;
		stEnemyBullet.angle = GetAngle(stEnemyBullet.x, stEnemyBullet.y, m_pPlayer->GetPosX(), m_pPlayer->GetPosY());


		m_vecEnemyBullets.push_back(stEnemyBullet);
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
			m_pPlayer->SetHP(m_pPlayer->GetHP() - stEnemyBullet.Damage);
		}
		else if (IntersectRect(&rt, &m_pPlayer->GetCollisionLeft(), &iter->rtEnemyBullet))
		{
			iter = m_vecEnemyBullets.erase(iter);
			m_pPlayer->SetHP(m_pPlayer->GetHP() - stEnemyBullet.Damage);
		}
		else if (IntersectRect(&rt, &m_pPlayer->GetCollisionRight(), &iter->rtEnemyBullet))
		{
			iter = m_vecEnemyBullets.erase(iter);

			if (m_pPlayer->GetHP() > 0)
			{
				m_pPlayer->SetHP(m_pPlayer->GetHP() - stEnemyBullet.Damage);
			}
		}
		else
		{
			iter++;
		}
	}

	//ÇÃ¿¡ÀÌ¾î ÃÑ¾Ë
	if (m_pPlayer->GetIsShoot() == true)
	{
		if (stPlayerBullet.ShootDelay > 0)
		{
 			--stPlayerBullet.ShootDelay;
		}
		if (stPlayerBullet.ShootDelay == 0)
		{
			stPlayerBullet.ShootDelay = 10;

			stPlayerBullet.x = m_pPlayer->GetPosX();
			stPlayerBullet.y = m_pPlayer->GetPosY();
			stPlayerBullet.speed = 10;
			stPlayerBullet.angle = GetAngle(stPlayerBullet.x, stPlayerBullet.y, m_pEnemy->GetPosX(), m_pEnemy->GetPosY());

			m_vecPlayerBullets.push_back(stPlayerBullet);
		}
	}
	else
	{
		stPlayerBullet.ShootDelay = 0;
	}

	for (auto iter = m_vecPlayerBullets.begin(); iter != m_vecPlayerBullets.end();)
	{
		iter->y -= iter->speed;

		RECT rt1;
		iter->rtPlayerBullet = RectMakeCenter((int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
		if ((IntersectRect(&rt1, &m_pEnemy->GetBoundingBox(), &iter->rtPlayerBullet)) || iter->y < 0)
		{
			iter = m_vecPlayerBullets.erase(iter);

			if (m_pEnemy->GetEnemyHP() > 0)
			{
				m_pEnemy->SetEnemyHP(m_pEnemy->GetEnemyHP() - m_pPlayer->GetDamage());
			}
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
	// Àû ÃÑ¾Ë
	for (auto iter = m_vecEnemyBullets.begin(); iter != m_vecEnemyBullets.end(); iter++)
	{
		EllipseMakeCenter(g_hDC, (int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
	}

	DeleteObject(hSelectPen);
	DeleteObject(hPen);

	HPEN hPen1 = (HPEN)CreatePen(0, 1, RGB(0, 0, 255));
	HPEN hSelectPen1 = (HPEN)SelectObject(g_hDC, hPen1);
	//ÇÃ·¹ÀÌ¾î ÃÑ¾Ë
	for (auto iter = m_vecPlayerBullets.begin(); iter != m_vecPlayerBullets.end(); iter++)
	{
		EllipseMakeCenter(g_hDC, (int)iter->x, (int)iter->y, (int)iter->radius * 2, (int)iter->radius * 2);
	}

	DeleteObject(hSelectPen1);
	DeleteObject(hPen1);
}

