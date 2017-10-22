#pragma once

class cPlayer;
class cEnemy;

struct tagEnemyBullet
{
	float	x, y;			// �Ѿ� �߾� ��ǥ
	float	speed;			// �Ѿ� �ӷ�
	float	angle;			// �Ѿ� ����
	float	radius;			// �Ѿ� ������

	RECT	rtEnemyBullet;

	int ShootDelay;
};

struct tagPlayerBullet
{
	float x, y;				// �Ѿ� �߾� ��ǥ
	float speed;			// �Ѿ� �ӷ�
	float angle;			// �Ѿ� ����
	float radius;			// �Ѿ� ������

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