#include "stdafx.h"
#include "cMainGame.h"
#include "cPlayer.h"
#include "cObjects.h"
#include "cMap.h"

cMainGame::cMainGame()
	: m_isPlaying(false)
{
	g_pImageManager->AddImage("Enemy", "images/boss.bmp", 112, 46, 1, 1, WINSIZEX / 2 + 56, 200, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Player", "images/Player.bmp", 128, 32, 4, 1, WINSIZEX / 2 + 16, WINSIZEY - 200, true, RGB(255, 0, 255));

	m_pPlayer = new cPlayer;
	m_pObjects = new cObjects;
	m_pMap = new cMap;
}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pObjects;
}

void cMainGame::Setup()
{
	m_pPlayer->Setup();	
	m_pObjects->Setup();
	// 오브젝트 클래스가 플레이어와 맵 클래스를 참조 받도록 한다.
//	m_pObjects->SetPlayer(m_pPlayer);
//	m_pObjects->SetMap(m_pMap);
	m_pMap->Setup();
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pObjects->Update();
		m_pPlayer->Update();
		m_pMap->Update();
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}
}

void cMainGame::Render()
{
	// 흰색으로 이미지를 칠한다.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pObjects->Render();
		m_pPlayer->Render();
		m_pMap->Render();
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}