#include "stdafx.h"
#include "cEnemy.h"
#include "cPlayer.h"

cEnemy::cEnemy()
{
	m_imgEnemy = NULL;
}

cEnemy::~cEnemy()
{
}

void cEnemy::Setup()
{

	m_imgEnemy = g_pImageManager->FindImage("Enemy");
	m_nEnemyHP = 1000;
}

void cEnemy::Update()
{
	//if (m_imgEnemy->GetPosX() < m_pPlayer->GetPosX() )
	//{
	//	m_imgEnemy->SetPosX(m_imgEnemy->GetPosX() - (m_pPlayer->GetPosX() - m_imgEnemy->GetPosX()) / 2);
	//}
}

void cEnemy::Render()
{	
	HPEN hPen = (HPEN)CreatePen(0, 3, RGB(255, 0, 0));
	HPEN hSelectPen = (HPEN)SelectObject(g_hDC, hPen);

	m_imgEnemy->Render(g_hDC, m_imgEnemy->GetBoundingBox().left, m_imgEnemy->GetBoundingBox().top, 112, 46);
	
	BoudingLineMake(g_hDC,
		m_imgEnemy->GetBoundingBox().left, 
		m_imgEnemy->GetBoundingBox().top,
		m_imgEnemy->GetFrameWidth(),
		m_imgEnemy->GetFrameHeight());

	DeleteObject(hSelectPen);
	DeleteObject(hPen);

	string str("Enemy HP : ");
	char szStr[128];

	str += itoa(m_nEnemyHP, szStr, 10);
	TextOutA(g_hDC, 100, 75, str.c_str(), str.length());
}

void cEnemy::CreateEnemy()
{
	stEnemy.fPosX = (float)m_imgEnemy->GetBoundingBox().left + (float)m_imgEnemy->GetFrameWidth() / 2 ;
	stEnemy.fPosY = (float)m_imgEnemy->GetBoundingBox().top + (float)m_imgEnemy->GetHeight() / 2 ;
	stEnemy.x = WINSIZEX / 2;
	stEnemy.y = WINSIZEY / 2;
}

