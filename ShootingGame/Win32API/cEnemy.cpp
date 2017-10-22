#include "stdafx.h"
#include "cEnemy.h"

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
}

void cEnemy::Update()
{

	for (m_iterEnemy = m_vecEnemy.begin(); m_iterEnemy != m_vecEnemy.end(); m_iterEnemy++)
	{
		CreateEnemy();

		m_iterEnemy->rtEnemy = { (int)m_iterEnemy->fPosX, (int)m_iterEnemy->fPosY, (int)m_imgEnemy->GetFrameWidth(), (int)m_imgEnemy->GetFrameHeight() };

		m_vecEnemy.push_back(stEnemy);
	}
}

void cEnemy::Render()
{
	for (m_iterEnemy = m_vecEnemy.begin(); m_iterEnemy != m_vecEnemy.end(); m_iterEnemy++)
	{
		if (m_imgEnemy != NULL)
		{
			BoudingLineMake(g_hDC, 
				//m_imgEnemy->GetBoundingBox().left, 
				//m_imgEnemy->GetBoundingBox().top,
				m_iterEnemy->fPosX, m_iterEnemy->fPosY,
				m_imgEnemy->GetFrameWidth(), 
				m_imgEnemy->GetFrameHeight());
			
			m_imgEnemy->Render(g_hDC, m_iterEnemy->fPosX, m_iterEnemy->fPosY, 112, 46);
		}
	}
	
//	m_imgEnemy->Render(g_hDC, m_imgEnemy->GetBoundingBox().left, m_imgEnemy->GetBoundingBox().top, 112, 46);
	
//	BoudingLineMake(g_hDC,
//		m_imgEnemy->GetBoundingBox().left, 
//		m_imgEnemy->GetBoundingBox().top,
//		m_imgEnemy->GetFrameWidth(),
//		m_imgEnemy->GetFrameHeight());
}

void cEnemy::CreateEnemy()
{
	stEnemy.fPosX = (float)m_imgEnemy->GetBoundingBox().left + (float)m_imgEnemy->GetFrameWidth() / 2 ;
	stEnemy.fPosY = (float)m_imgEnemy->GetBoundingBox().top + (float)m_imgEnemy->GetHeight() / 2 ;
	stEnemy.x = WINSIZEX / 2;
	stEnemy.y = WINSIZEY / 2;
}

