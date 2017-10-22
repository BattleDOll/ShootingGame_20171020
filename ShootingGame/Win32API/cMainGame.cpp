#include "stdafx.h"
#include "cMainGame.h"
#include "cPlayer.h"
#include "cEnemy.h"
#include "cBullet.h"

cMainGame::cMainGame()
	: m_isPlaying(false)
{
	g_pImageManager->AddImage("Enemy", "images/boss.bmp", 112, 46, 1, 1, WINSIZEX / 2 + 56, 200, true, RGB(255, 0, 255));
	g_pImageManager->AddImage("Player", "images/Player.bmp", 128, 32, 4, 1, WINSIZEX / 2 + 16, WINSIZEY - 200, true, RGB(255, 0, 255));

	m_pPlayer = new cPlayer;
	m_pEnemy = new cEnemy;
	m_pBullet = new cBullet;
}

cMainGame::~cMainGame()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pBullet;
}

void cMainGame::Setup()
{
	m_pPlayer->Setup();	
	m_pEnemy->Setup();

	// �ҷ����� �÷��̾�� ���ʹ� ����? 
	m_pBullet->Setup();
	m_pBullet->SetPlayer(m_pPlayer);
	m_pBullet->SetEnemy(m_pEnemy);
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pEnemy->Update();
		m_pPlayer->Update();
		m_pBullet->Update();
	}
	else if (g_pKeyManager->isOnceKeyDown(VK_RETURN))
	{
		Setup();
		m_isPlaying = true;
	}



}

void cMainGame::Render()
{
	// ������� �̹����� ĥ�Ѵ�.
	PatBlt(g_hDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	if (m_isPlaying)
	{
		m_pEnemy->Render();
		m_pPlayer->Render();
		m_pBullet->Render();
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}