#pragma once
class cScore
{
private:
	cImage* m_pScore;

	int nScore;			//����
	int nLength;		//������ �ڸ���
	int	nRemainder;		// ������ �ڸ����� ���ϱ� ���� ��



public:
	cScore();
	~cScore();

	void Setup();
	void Update();
	void Render();

	int GetScore() { nScore; }
	void SetScore(int score) { nScore = score; }
};

