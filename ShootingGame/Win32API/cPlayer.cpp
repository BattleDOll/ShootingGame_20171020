#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayer = NULL;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_pPlayer = g_pImageManager->FindImage("Player");
}

void cPlayer::Update()
{
	if (m_pPlayer->GetBoundingBox(3, 0, 20, 0).left > 0 && g_pKeyManager->isStayKeyDown('A'))
	{
		m_pPlayer->SetPosX(m_pPlayer->GetPosX() - 5.0f);
	}
	else if (m_pPlayer->GetBoundingBox(-3, 0, 20, 0).right  < WINSIZEX && g_pKeyManager->isStayKeyDown('D'))
	{
		m_pPlayer->SetPosX(m_pPlayer->GetPosX() + 5.0f);
	}
	if (m_pPlayer->GetBoundingBox().bottom  < WINSIZEY && g_pKeyManager->isStayKeyDown('S'))
	{
		m_pPlayer->SetPosY(m_pPlayer->GetPosY() + 5.0f);
	}
	else if (m_pPlayer->GetBoundingBox().top  > 0 && g_pKeyManager->isStayKeyDown('W'))
	{
		m_pPlayer->SetPosY(m_pPlayer->GetPosY() - 5.0f);
	}

	if (g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{
	}
}

void cPlayer::Render()
{
	if (m_pPlayer != NULL)
	{
		if (g_pKeyManager->isStayKeyDown('A'))
		{
			Rectangle(g_hDC,
				m_pPlayer->GetBoundingBox(3, 0, 20, 0).left,
				m_pPlayer->GetBoundingBox(3, 0, 20, 0).top,
				m_pPlayer->GetBoundingBox(3, 0, 20, 0).right,
				m_pPlayer->GetBoundingBox(3, 0, 20, 0).bottom);

			m_pPlayer->FrameRender(g_hDC, 
				m_pPlayer->GetPosX() - (m_pPlayer->GetFrameWidth() / 2), 
				m_pPlayer->GetPosY() - (m_pPlayer->GetFrameHeight() / 2), 1, 0);
		}
		else if (g_pKeyManager->isStayKeyDown('D'))
		{
			Rectangle(g_hDC,
				m_pPlayer->GetBoundingBox(-3, 0, 20, 0).left,
				m_pPlayer->GetBoundingBox(-3, 0, 20, 0).top,
				m_pPlayer->GetBoundingBox(-3, 0, 20, 0).right,
				m_pPlayer->GetBoundingBox(-3, 0, 20, 0).bottom);

			m_pPlayer->FrameRender(g_hDC, 
				m_pPlayer->GetPosX() - (m_pPlayer->GetFrameWidth() / 2), 
				m_pPlayer->GetPosY() - (m_pPlayer->GetFrameHeight() / 2), 2, 0);
		}
		else
		{
			Rectangle(g_hDC, 
				m_pPlayer->GetBoundingBox().left, 
				m_pPlayer->GetBoundingBox().top, 
				m_pPlayer->GetBoundingBox().right, 
				m_pPlayer->GetBoundingBox().bottom);

			m_pPlayer->FrameRender(g_hDC, 
				m_pPlayer->GetPosX() - (m_pPlayer->GetFrameWidth() / 2),
				m_pPlayer->GetPosY() - (m_pPlayer->GetFrameHeight() / 2), 0, 0);
		}
	}
}