#pragma once

struct tagEnemy
{
	float	x, y;
	float	fPosX, fPosY;

	RECT	rtEnemy;

	int		ShootDelay;
};

class cEnemy
{
private:
	vector<tagEnemy>			m_vecEnemy;
	vector<tagEnemy>::iterator	m_iterEnemy;
	tagEnemy stEnemy;

	cImage*	m_imgEnemy;

	float	m_fMoveSpeed;

public:
	cEnemy();
	~cEnemy();

	void Setup();
	void Update();
	void Render();

	float GetPosX() { return m_imgEnemy->GetPosX(); }
	float GetPosY() { return m_imgEnemy->GetPosY(); }

	void CreateEnemy();

	int GetShootDelay() { return m_iterEnemy->ShootDelay; }
	void SetShootDelay(int delay) { m_iterEnemy->ShootDelay = delay; }
};