#pragma once
#include "cImage.h"

class cPlayer;
//class cMap;
struct tagObject
{
	cImage*	m_pObjImage;

	float	x;
	float	y;
	float	fPosX, fPosY;

	int		shootDelay;
};
struct tagBullet
{
	float x, y;				// �Ѿ� �߾� ��ǥ
	float speed;			// �Ѿ� �ӷ�
	float angle;			// �Ѿ� ����
	float radius;			// �Ѿ� ������
};

class cObjects
{
private:
	vector<tagObject>				m_vecObjects;	// ������Ʈ ����
	vector<tagObject>::iterator		m_vecIter;		// ������Ʈ ���� �ݺ���
	tagObject stObject;

	vector<tagBullet>				m_vecBullets;	// �Ѿ� ����

	RECT	rt;

	int		m_nDelay;

	float	m_fMoveSpeed;

	cPlayer*	m_pPlayer;		// �÷��̾� ���� ������
//	cMap*		m_pMap;			// �� ���� ������

public:
	cObjects();
	~cObjects();

	void Setup();
	void Update();
	void Render();

	void SetPlayer(cPlayer* player) { m_pPlayer = player; }
//	void SetMap(cMap* map) { m_pMap = map; }
};

