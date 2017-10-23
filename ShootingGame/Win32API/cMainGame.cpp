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
	g_pImageManager->AddImage("HpBarBack", "images/progressBarBack.bmp", 50, 10);
	g_pImageManager->AddImage("HpBarFront", "images/progressBarFront.bmp", 50, 10);

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

	// 불렛에서 플레이어와 에너미 참조? 
	m_pBullet->Setup();
	m_pBullet->SetPlayer(m_pPlayer);
	m_pBullet->SetEnemy(m_pEnemy);

	nRandDelay = GetRandom(500, 1000);
	m_nGenDelay = 0;
}

void cMainGame::Update()
{
	cGameNode::Update();

	if (m_isPlaying)
	{
		m_pEnemy->Update();
		m_pPlayer->Update();
		m_pBullet->Update();

		if (m_nGenDelay > 0)
		{
			--m_nGenDelay;
		}
		else if (m_nGenDelay == 0)
		{
			m_nGenDelay = nRandDelay;
			MakeItem();
		}

		MoveItem();
		ItemGet();
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
		m_pEnemy->Render();
		m_pPlayer->Render();
		m_pBullet->Render();
		RenderItem();

		string str("m_nBuffTime: ");
		char szStr[128];

		str += itoa(m_nBuffTime, szStr, 10);
		TextOutA(g_hDC, 300, 50, str.c_str(), str.length());
	}
	else
	{
		TextOut(g_hDC, WINSIZEX / 2 - 200, WINSIZEY / 2, "Enter to Start", strlen("Enter to Start"));
	}
}
// 아이템 클래스 벡터화
void cMainGame::MakeItem()
{
		cItem Item;

		Item.Setup();

		m_vecItem.push_back(Item);
}

void cMainGame::MoveItem()
{
	for (auto iter = m_vecItem.begin(); iter != m_vecItem.end();)
	{
		iter->Update();
		if(iter->GetPosY() > WINSIZEY + 100)
		{
			iter = m_vecItem.erase(iter);
		}
		else
		{
			iter++;
		}
	}

	if (m_nBuffTime > 0)
	{
		--m_nBuffTime;
	}
	else if (m_nBuffTime == 0)
	{
		m_pPlayer->SetDamage(10);
	}
}

void cMainGame::RenderItem()
{
	for (auto iter = m_vecItem.begin(); iter != m_vecItem.end(); iter++)
	{
		iter->Render();
	}
}

void cMainGame::ItemGet()
{
	for (auto iter = m_vecItem.begin(); iter != m_vecItem.end();)
	{
		RECT rt;
		if(IntersectRect(&rt, &iter->GetRect(), &m_pPlayer->GetCollisionNomal()))
		{
			iter = m_vecItem.erase(iter);
			int itemRand = GetRandom(1, 100);
			if (itemRand > 50)
			{
				m_pPlayer->SetHP(m_pPlayer->GetHP() + 100);
			}
			else
			{
				m_nBuffTime = 1500;

				m_pPlayer->SetDamage(m_pPlayer->GetDamage() + 10);
			}
		}
		else
		{
			iter++;
		}
	}
}
