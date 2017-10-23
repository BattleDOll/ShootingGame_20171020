#pragma once
#include "cGameNode.h"
#include "cItem.h"

class cPlayer;
class cEnemy;
class cBullet;

class cMainGame : public cGameNode
{
private:
	cPlayer*		m_pPlayer;
	cEnemy*			m_pEnemy;
	cBullet*		m_pBullet;

	int		m_nGenDelay;
	int		nRandDelay;

	bool			m_isPlaying;

	vector<cItem>	m_vecItem;

public:
	cMainGame();
	~cMainGame();

	void Setup();
	virtual void Update() override;
	virtual void Render() override;

	void MakeItem();
	void MoveItem();
	void RenderItem();
};