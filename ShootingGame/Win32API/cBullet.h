#pragma once

class cPlayer;
class cEnemy;

struct tagEnemyBullet
{
	float	x, y;			// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥
	float	speed;			// ÃÑ¾Ë ¼Ó·Â
	float	angle;			// ÃÑ¾Ë ¹æÇâ
	float	radius;			// ÃÑ¾Ë ¹ÝÁö¸§

	RECT	rtEnemyBullet;

	int ShootDelay;
};

struct tagPlayerBullet
{
	float x, y;				// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥
	float speed;			// ÃÑ¾Ë ¼Ó·Â
	float angle;			// ÃÑ¾Ë ¹æÇâ
	float radius;			// ÃÑ¾Ë ¹ÝÁö¸§

	int ShootDelay;
};

class cBullet
{
private:
	cPlayer*					m_pPlayer;
	cEnemy*						m_pEnemy;

	tagEnemyBullet				enemyBullet;
	tagPlayerBullet				playerBullet;
	vector<tagEnemyBullet>		m_vecEnemyBullets;
	vector<tagPlayerBullet>		m_vecPlayerBullets;

public:
	cBullet();
	~cBullet();

	void Setup();
	void Update();
	void Render();

	void SetPlayer(cPlayer* player) { m_pPlayer = player; }
	void SetEnemy(cEnemy* Enemy) { m_pEnemy = Enemy; }
};