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
	m_nEnemyHP = 1000;
}

void cEnemy::Update()
{
	//if (m_pEnemy->GetPosX() < m_pPlayer->GetPosX())
	//{
	//}
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

	string str("Enemy HP : ");
	char szStr[128];

	str += itoa(m_nEnemyHP, szStr, 10);
	TextOutA(g_hDC, 100, 75, str.c_str(), str.length());
}

void cEnemy::CreateEnemy()
{
	//stEnemy.fPosX = (float)m_pEnemy->GetBoundingBox().left + (float)m_pEnemy->GetFrameWidth() / 2 ;
	//stEnemy.fPosY = (float)m_pEnemy->GetBoundingBox().top + (float)m_pEnemy->GetHeight() / 2 ;
	//stEnemy.x = WINSIZEX / 2;
	//stEnemy.y = WINSIZEY / 2;
}

