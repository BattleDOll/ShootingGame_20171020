#pragma once

class cPlayer;
class cEnemy;

struct tagEnemyBullet
{
	RECT	rtEnemyBullet;

	float	x, y;			// �Ѿ� �߾� ��ǥ
	float	x1, y1;			// �Ѿ� �߾� ��ǥ

	float	speed;			// �Ѿ� �ӷ�
	float	angle;			// �Ѿ� ����
	float	radius;			// �Ѿ� ������

	int		ShootDelay;
	int		Damage;
};

struct tagPlayerBullet
{
	RECT	rtPlayerBullet;

	float	x, y;				// �Ѿ� �߾� ��ǥ
	float	x1, y1;
	float	speed;			// �Ѿ� �ӷ�
	float	speed1;
	float	angle;			// �Ѿ� ����
	float	radius;			// �Ѿ� ������

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