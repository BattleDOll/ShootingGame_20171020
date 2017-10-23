#pragma once

class cPlayer;
class cProgressBar;

struct tagEnemy
{
	RECT	rtEnemy;

	float	x, y;
	float	fPosX, fPosY;

	int		ShootDelay;
};

class cEnemy
{
private:
	cPlayer*			m_pPlayer;
	cImage*				m_pEnemy;
	cProgressBar*		m_pHpBar;

	tagEnemy			stEnemy;

	vector<tagEnemy>			m_vecEnemy;
	vector<tagEnemy>::iterator	m_iterEnemy;

	float		m_fMaxHp;
	float		m_fCurrHp;
	float		m_fMoveSpeed;

	int			m_nEnemyDamage;
	int			m_nEnemyHP;

public:
	cEnemy();
	~cEnemy();

	void Setup();
	void Update();
	void Render();

	RECT GetBoundingBox() { return m_pEnemy->GetBoundingBox(); }

	float GetPosX() { return m_pEnemy->GetPosX(); }
	float GetPosY() { return m_pEnemy->GetPosY(); }

	int GetEnemyHP() { return m_nEnemyHP; }
	void SetEnemyHP(int hp) { m_nEnemyHP = hp; }
	int GetEnemyDamage() { return m_nEnemyDamage; }
	int SetEnemyDamage(int damage) { m_nEnemyDamage = damage; }
	int GetShootDelay() { return m_iterEnemy->ShootDelay; }
	void SetShootDelay(int delay) { m_iterEnemy->ShootDelay = delay; }

	void CreateEnemy();
};