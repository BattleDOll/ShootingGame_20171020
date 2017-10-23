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
	int				m_nPlayerDamage;

	bool			m_isShoot;

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	RECT GetCollisionNomal() { return m_pPlayer->GetBoundingBox(); }
	RECT GetCollisionLeft() { return m_pPlayer->GetBoundingBox(3, 0, 20, 0); }
	RECT GetCollisionRight() { return m_pPlayer->GetBoundingBox(-3, 0, 20, 0); }

	float GetPosX() { return m_pPlayer->GetPosX(); }
	float GetPosY() { return m_pPlayer->GetPosY(); }
	int GetHP() { return m_fCurrHp; }
	void SetHP(int hp) { m_fCurrHp = hp; }
	int GetDamage() { return m_nPlayerDamage; }
	void SetDamage(int damage) { m_nPlayerDamage = damage; }

	bool GetIsShoot() { return m_isShoot; }
};