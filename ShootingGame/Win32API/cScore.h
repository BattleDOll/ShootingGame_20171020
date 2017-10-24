#pragma once
class cScore
{
private:
	cImage* m_pScore;

	int nScore;			//점수
	int nLength;		//점수의 자리수
	int	nRemainder;		// 점수의 자리수를 구하기 위한 몫



public:
	cScore();
	~cScore();

	void Setup();
	void Update();
	void Render();

	int GetScore() { nScore; }
	void SetScore(int score) { nScore = score; }
};

