#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
	m_pPlayerImage = NULL;
}

cPlayer::~cPlayer()
{
}

void cPlayer::Setup()
{
	m_pPlayerImage = g_pImageManager->FindImage("Player");
}

void cPlayer::Update()
{
	if (m_pPlayerImage->GetBoundingBox().left > 0 && g_pKeyManager->isStayKeyDown('A'))
	{
		m_pPlayerImage->SetPosX(m_pPlayerImage->GetPosX() - 5.0f);
	}
	else if (m_pPlayerImage->GetBoundingBox().right  < WINSIZEX && g_pKeyManager->isStayKeyDown('D'))
	{
		m_pPlayerImage->SetPosX(m_pPlayerImage->GetPosX() + 5.0f);
	}
	else if (m_pPlayerImage->GetBoundingBox().bottom  < WINSIZEY && g_pKeyManager->isStayKeyDown('S'))
	{
		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() + 5.0f);
	}
	else if (m_pPlayerImage->GetBoundingBox().top  > 0 && g_pKeyManager->isStayKeyDown('W'))
	{
		m_pPlayerImage->SetPosY(m_pPlayerImage->GetPosY() - 5.0f);
	}

	if (g_pKeyManager->isOnceKeyDown(VK_SPACE))
	{

	}
}

void cPlayer::Render()
{
	Rectangle(g_hDC, m_pPlayerImage->GetBoundingBox().left, m_pPlayerImage->GetBoundingBox().top, m_pPlayerImage->GetBoundingBox().right, m_pPlayerImage->GetBoundingBox().bottom);
	if (m_pPlayerImage != NULL)
	{
		m_pPlayerImage->FrameRender(g_hDC, m_pPlayerImage->GetPosX() - (m_pPlayerImage->GetFrameWidth() / 2), m_pPlayerImage->GetPosY() - (m_pPlayerImage->GetFrameHeight() / 2), 0, 0);
	}
}