#pragma once
#include "define.h"

class Stage
{
	// Render, Update
public:
	Stage();
	~Stage();
public:
	char m_cStage[MAP_Y][MAP_X];
private:
	POINT m_tStart;
	POINT m_tEnd;
	POINT m_tSpawner;
	int score = 0;
public:
	POINT GetStart() { return m_tStart; }
	POINT GetEnd() { return m_tEnd; }
	POINT GetSpawner() { return m_tSpawner; }
	char GetStart(int x, int y) { return m_cStage[y][x]; }
	int GetScore() { return this->score; }
	void SetScore(int score) { this->score = score; }
public:
	bool Init(const char* _pFilename);
	void Render();
	void Update();
};