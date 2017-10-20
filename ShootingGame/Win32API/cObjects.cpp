#include "stdafx.h"
#include "cObjects.h"
#include "cPlayer.h"

cObjects::cObjects()
{
	stObject.m_pObjImage = NULL;
}

cObjects::~cObjects()
{
}

void cObjects::Setup()
{
	stObject.m_pObjImage = g_pImageManager->FindImage("Enemy");
	stObject.shootDelay = 10;
}

void cObjects::Update()
{	
	for (m_vecIter = m_vecObjects.begin(); m_vecIter != m_vecObjects.end(); ++m_vecIter)
	{
		// ===== 총알 발사 =============
		if (m_vecIter->shootDelay > 0)
		{
			--m_vecIter->shootDelay;
		}
		else if (m_vecIter->shootDelay == 0)
		{
			m_vecIter->shootDelay = 10;

			tagBullet bullet;
			bullet.x = stObject.m_pObjImage->GetPosX();
			bullet.y = stObject.m_pObjImage->GetPosY();
			bullet.speed = 5;
			bullet.radius = 5;

			bullet.angle = GetAngle(m_pPlayer->GetPosX(), m_pPlayer->GetPosY(), bullet.x, bullet.y);

			m_vecBullets.push_back(bullet);
		}
		// ==============================
	}

	for (auto iter = m_vecBullets.begin(); iter != m_vecBullets.end();)
	{
		iter->x += cosf(iter->angle / 180 * PI) * iter->speed;
		iter->y -= sinf(iter->angle / 180 * PI) * iter->speed;

		if (iter->y < 0 - iter->radius && iter->y > WINSIZEY + iter->radius) // 화면 하단으로 벗어난 경우
		{
			iter = m_vecBullets.erase(iter);
		}
		else
		{
			++iter;
		}
	}
}

void cObjects::Render()
{
	for (auto iter = m_vecBullets.begin(); iter != m_vecBullets.end(); ++iter)
	{
		EllipseMakeCenter(g_hDC, iter->x, iter->y, iter->radius * 2, iter->radius * 2);
	}

	Rectangle(g_hDC, stObject.m_pObjImage->GetBoundingBox().left, stObject.m_pObjImage->GetBoundingBox().top, stObject.m_pObjImage->GetBoundingBox().right, stObject.m_pObjImage->GetBoundingBox().bottom);

	if (stObject.m_pObjImage != NULL)
	{
		stObject.m_pObjImage->Render(g_hDC, stObject.m_pObjImage->GetPosX() - (stObject.m_pObjImage->GetFrameWidth() / 2), stObject.m_pObjImage->GetPosY() - (stObject.m_pObjImage->GetFrameHeight() / 2 ) , 112, 46);
	}
}