#pragma once

class cPlayer;
class cProgressBar;

class cEnemy
{
private:
	cPlayer*			m_pPlayer;
	cImage*				m_pEnemy;
	cProgressBar*		m_pHpBar;

	RECT	rtEnemy;

	float		m_fMaxHp;
	float		m_fCurrHp;
	float		m_fMoveSpeed;
	float		x, y;
	float		m_fPosX, m_fPosY;

	int			m_nEnemyDamage;
	int			ShootDelay;

public:
	cEnemy();
	~cEnemy();

	void Setup();
	void Update();
	void Render();

	RECT GetBoundingBox() { return m_pEnemy->GetBoundingBox(); }

	float GetPosX() { return m_pEnemy->GetPosX(); }
	float GetPosY() { return m_pEnemy->GetPosY(); }

	int GetEnemyHP() { return m_fCurrHp; }
	void SetEnemyHP(int hp) { m_fCurrHp = hp; }
	int GetEnemyDamage() { return m_nEnemyDamage; }
	int SetEnemyDamage(int damage) { m_nEnemyDamage = damage; }
	int GetShootDelay() { return ShootDelay; }
	void SetShootDelay(int delay) { ShootDelay = delay; }
};