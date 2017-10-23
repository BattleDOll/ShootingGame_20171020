#include "stdafx.h"
#include "cEnemy.h"
#include "cPlayer.h"
#include "cProgressBar.h"

cEnemy::cEnemy()
{
	m_pEnemy = NULL;
	m_pHpBar = NULL;
}

cEnemy::~cEnemy()
{
}

void cEnemy::Setup()
{
	m_pEnemy = g_pImageManager->FindImage("Enemy");

	m_pHpBar = new cProgressBar("HpBarBack", "HpBarFront", m_pEnemy->GetFrameWidth(), 5);
	m_fMaxHp = 1000;
	m_fCurrHp = 1000;
	m_pHpBar->SetGauge(m_fMaxHp, m_fCurrHp);
}

void cEnemy::Update()
{
	m_fPosX = m_pEnemy->GetPosX();
	m_fPosY = m_pEnemy->GetPosY() - 40;

	m_pHpBar->SetPosX(m_fPosX);
	m_pHpBar->SetPosY(m_fPosY - m_pEnemy->GetFrameHeight() / 2 + 32);
	m_pHpBar->SetGauge(m_fMaxHp, m_fCurrHp);
	m_pHpBar->Update();
}

void cEnemy::Render()
{	
	HPEN hPen = (HPEN)CreatePen(0, 3, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	m_pEnemy->Render(g_hDC, m_pEnemy->GetBoundingBox().left, m_pEnemy->GetBoundingBox().top, 112, 46);
	
	BoudingLineMake(g_hDC,
		m_pEnemy->GetBoundingBox().left, 
		m_pEnemy->GetBoundingBox().top,
		m_pEnemy->GetFrameWidth(),
		m_pEnemy->GetFrameHeight());

	DeleteObject(hSelectPen);
	DeleteObject(hPen);

	if (m_pHpBar != NULL)
	{
		m_pHpBar->Render();
	}

	string str("Enemy HP : ");
	char szStr[128];

	str += itoa(m_fCurrHp, szStr, 10);
	TextOutA(g_hDC, 500, 50, str.c_str(), str.length());
}

