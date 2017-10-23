#include "stdafx.h"
#include "cItem.h"


cItem::cItem()
{
}

cItem::~cItem()
{
}

void cItem::Setup()
{
	nRandX = GetRandom(100, 600);
	nRandDelay = GetRandom(500, 1000);
	m_fPosX = nRandX;
	m_fPosY = -10;
	m_nSizeW = 10;
	m_nSizeH = 10;

	m_nGenDelay = 0;

	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cItem::Update()
{
	m_fPosY += 5;
	m_rtBody = RectMakeCenter(m_fPosX, m_fPosY, m_nSizeW, m_nSizeH);
}

void cItem::Render()
{
	Rectangle(g_hDC, m_rtBody.left, m_rtBody.top, m_rtBody.right, m_rtBody.bottom);
}