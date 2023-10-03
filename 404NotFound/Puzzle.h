#pragma once
#include "define.h"
#include <vector>

class Puzzle
{
public:
	Puzzle();
	~Puzzle();
public:
	int _clearPercent = 0;
	std::vector<POINT> checkPos;
	POINT starPos;
private:
	static Puzzle* m_pInst;
private:
	char map[STAR_Y][STAR_X];
	int dir = 0;
public:
	static Puzzle* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Puzzle;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init();
	void Update();
	void Render();
};

