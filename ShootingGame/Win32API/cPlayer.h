#pragma once
#include "cImage.h"



class cPlayer
{
private:
	cImage*		m_pPlayerImage;		// 플레이어 이미지 파일
	RECT		rt;

	int			m_nDamageDelay;		// 연속 데미지 방지용 딜레이(무적 모드)

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

