#pragma once

class cPlayer
{
private:
	cImage*		m_pPlayer;		// �÷��̾� �̹��� ����	

	int			m_nDamageDelay;		// ���� ������ ������ ������(���� ���)

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

	RECT rt;
	RECT GetCollisionNomal() { return m_pPlayer->GetBoundingBox(); }
	RECT GetCollisionLeft() { return m_pPlayer->GetBoundingBox(3, 0, 20, 0); }
	RECT GetCollisionRight() { return m_pPlayer->GetBoundingBox(-3, 0, 20, 0); }

	float GetPosX() { return m_pPlayer->GetPosX(); }
	float GetPosY() { return m_pPlayer->GetPosY(); }
};

