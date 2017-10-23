#pragma once

class cItem
{
private:
	int		nRandX;
	int		nRandDelay;
	int		m_nSizeW;
	int		m_nSizeH;
	int		m_nGenDelay;
	float	m_fPosX;
	float	m_fPosY;


	RECT   m_rtBody;

public:
	cItem();
	~cItem();

	void Setup();
	void Update();
	void Render();

	float GetPosX() { return m_fPosX; }
	void  SetPosX(float x) { m_fPosX = x; }
	float GetPosY() { return m_fPosY; }
	void  SetPosY(float y) { m_fPosX = y; }
};

