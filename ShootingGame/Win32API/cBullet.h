#pragma once

class cPlayer;
class cEnemy;

struct tagEnemyBullet
{
	RECT	rtEnemyBullet;

	float	x, y;			// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥
	float	x1, y1;			// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥

	float	speed;			// ÃÑ¾Ë ¼Ó·Â
	float	angle;			// ÃÑ¾Ë ¹æÇâ
	float	radius;			// ÃÑ¾Ë ¹ÝÁö¸§

	int		ShootDelay;
	int		Damage;
};

struct tagPlayerBullet
{
	RECT	rtPlayerBullet;

	float	x, y;				// ÃÑ¾Ë Áß¾Ó ÁÂÇ¥
	float	x1, y1;
	float	speed;			// ÃÑ¾Ë ¼Ó·Â
	float	speed1;
	float	angle;			// ÃÑ¾Ë ¹æÇâ
	float	radius;			// ÃÑ¾Ë ¹ÝÁö¸§

	int		ShootDelay;
	int		Damage;
};

class cBullet
{
private:
	cPlayer*					m_pPlayer;
	cEnemy*						m_pEnemy;

	tagEnemyBullet				stEnemyBullet;
	tagPlayerBullet				stPlayerBullet;

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