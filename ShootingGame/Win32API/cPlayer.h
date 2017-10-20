#pragma once
#include "cImage.h"



class cPlayer
{
private:
	cImage*		m_pPlayerImage;		// �÷��̾� �̹��� ����
	RECT		rt;

	int			m_nDamageDelay;		// ���� ������ ������ ������(���� ���)

public:
	cPlayer();
	~cPlayer();

	void Setup();
	void Update();
	void Render();

//	RECT GetBoundingBox() { return m_pPlayerImage->GetBoundingBox(); }
	float GetPosX() { return m_pPlayerImage->GetPosX(); }
	float GetPosY() { return m_pPlayerImage->GetPosY(); }
};

