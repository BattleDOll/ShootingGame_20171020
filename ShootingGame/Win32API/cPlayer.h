#pragma once

class cProgressBar;

class cPlayer
{
private:
	cImage*			m_pPlayer;		// �÷��̾� �̹��� ����
	cProgressBar*	m_pHpBar;

	float			m_fPosX;
	float			m_fPosY;
	float			m_fMaxHp;
	float			m_fCurrHp;

	int				m_nDamageDelay;		// ���� ������ ������ ������(���� ���)
//	int				m_nPlayerHP;
	int				m_nPlayerDamage;

	bool			m_isShoot;

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

//	RECT rt;
	RECT GetCollisionNomal() { return m_pPlayer->GetBoundingBox(); }
	RECT GetCollisionLeft() { return m_pPlayer->GetBoundingBox(3, 0, 20, 0); }
	RECT GetCollisionRight() { return m_pPlayer->GetBoundingBox(-3, 0, 20, 0); }

	float GetPosX() { return m_pPlayer->GetPosX(); }
	float GetPosY() { return m_pPlayer->GetPosY(); }
	int GetPlayerHP() { return m_fCurrHp; }
	void SetPlayerHP(int hp) { m_fCurrHp = hp; }

	bool GetIsShoot() { return m_isShoot; }
};