#include "stdafx.h"
#include "cPlayer.h"
#include "cProgressBar.h"


cPlayer::cPlayer()
{
	m_pPlayer = NULL;
	m_pHpBar = NULL;
}

cPlayer::~cPlayer()
{
	vector<string> saveData;
	char temp[128];

	saveData.push_back(itoa(m_fPosX, temp, 10));
	saveData.push_back(itoa(m_fPosY, temp, 10));
	saveData.push_back(itoa(m_fCurrHp, temp, 10));

	g_pFileDataManager->txtSave("PlayerData.txt", saveData );
}

void cPlayer::Setup()
{
	m_pPlayer = g_pImageManager->FindImage("Player");
	m_isShoot = false;
	m_nPlayerDamage = 10;

	m_pHpBar = new cProgressBar("HpBarBack", "HpBarFront", m_pPlayer->GetFrameWidth(), 5);
	m_fMaxHp = 100;
	m_fCurrHp = 100;
	m_pHpBar->SetGauge(m_fMaxHp, m_fCurrHp);

	vector<string> vecLoad = g_pFileDataManager->txtLoad("PlayerData.txt");

	if (!vecLoad.empty())
	{
		m_pPlayer->SetPosX(atoi(vecLoad[0].c_str()));
		m_pPlayer->SetPosY(atoi(vecLoad[1].c_str()));
		m_fCurrHp = atoi(vecLoad[2].c_str());
	}
}

void cPlayer::Update()
{
	if (g_pKeyManager->isStayKeyDown('A') || g_pKeyManager->isStayKeyDown(VK_LEFT))
	{
		if (m_pPlayer->GetBoundingBox(3, 0, 20, 0).left > 0)
		{
			m_pPlayer->SetPosX(m_pPlayer->GetPosX() - 5.0f);
		}
	}
	else if (g_pKeyManager->isStayKeyDown('D') || g_pKeyManager->isStayKeyDown(VK_RIGHT))
	{
		if (m_pPlayer->GetBoundingBox(-3, 0, 20, 0).right < WINSIZEX)
		{
			m_pPlayer->SetPosX(m_pPlayer->GetPosX() + 5.0f);
		}
	}
	if (g_pKeyManager->isStayKeyDown('S') || g_pKeyManager->isStayKeyDown(VK_DOWN))
	{
		if (m_pPlayer->GetBoundingBox().bottom < WINSIZEY)
		{
			m_pPlayer->SetPosY(m_pPlayer->GetPosY() + 5.0f);
		}
	}
	else if (g_pKeyManager->isStayKeyDown('W') || g_pKeyManager->isStayKeyDown(VK_UP))
	{
		if (m_pPlayer->GetBoundingBox().top > 0)
		{
			m_pPlayer->SetPosY(m_pPlayer->GetPosY() - 5.0f);
		}
	}

	if (g_pKeyManager->isStayKeyDown(VK_SPACE))
	{
		m_isShoot = true;
	}
	else
	{
		m_isShoot = false;
	}

	m_fPosX = m_pPlayer->GetPosX();
	m_fPosY = m_pPlayer->GetPosY();

	m_pHpBar->SetPosX(m_fPosX);
	m_pHpBar->SetPosY(m_fPosY - m_pPlayer->GetFrameHeight() / 2 + 32);
	m_pHpBar->SetGauge(m_fMaxHp, m_fCurrHp);
	m_pHpBar->Update();
}

void cPlayer::Render()
{
	HPEN hPen1 = (HPEN)CreatePen(0, 1, RGB(0, 0, 255));
	HPEN hSelectPen1 = (HPEN)SelectObject(g_hDC, hPen1);

	if (m_pPlayer != NULL)
	{
		if (g_pKeyManager->isStayKeyDown('A') || g_pKeyManager->isStayKeyDown(VK_LEFT))
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
		else if (g_pKeyManager->isStayKeyDown('D') || g_pKeyManager->isStayKeyDown(VK_RIGHT))
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

	DeleteObject(hSelectPen1);
	DeleteObject(hPen1);

	if (m_pHpBar != NULL)
	{
		m_pHpBar->Render();
	}

	string str("Player HP : ");
	char szStr[128]; 

	str += itoa(m_fCurrHp, szStr, 10);
	TextOutA(g_hDC, 100, 50, str.c_str(), str.length());

	str = "Damage: ";
	str += itoa(m_nPlayerDamage, szStr, 10);
	TextOutA(g_hDC, 100, 100, str.c_str(), str.length());

	//str = "ปýธํทย : ";
	//str += itoa(m_nLife, szStr, 10);
	//TextOutA(g_hDC, 100, 75, str.c_str(), str.length());
}