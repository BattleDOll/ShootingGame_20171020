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
	float x, y;				// 총알 중앙 좌표
	float speed;			// 총알 속력
	float angle;			// 총알 방향
	float radius;			// 총알 반지름
};

class cObjects
{
private:
	vector<tagObject>				m_vecObjects;	// 오브젝트 벡터
	vector<tagObject>::iterator		m_vecIter;		// 오브젝트 벡터 반복자
	tagObject stObject;

	vector<tagBullet>				m_vecBullets;	// 총알 벡터

	RECT	rt;

	int		m_nDelay;

	float	m_fMoveSpeed;

	cPlayer*	m_pPlayer;		// 플레이어 참조 포인터
//	cMap*		m_pMap;			// 맵 참조 데이터

public:
	cObjects();
	~cObjects();

	void Setup();
	void Update();
	void Render();

	void SetPlayer(cPlayer* player) { m_pPlayer = player; }
//	void SetMap(cMap* map) { m_pMap = map; }
};

