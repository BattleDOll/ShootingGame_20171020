#pragma once
#include "cGameNode.h"

class cPlayer;
class cEnemy;
class cBullet;

class cMainGame : public cGameNode
{
private:
	bool			m_isPlaying;

	cPlayer*		m_pPlayer;
	cEnemy*			m_pEnemy;
	cBullet*		m_pBullet;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;
};