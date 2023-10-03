#pragma once
#include "define.h"
#include "Stage.h"
class Player;
class Enemy
{
public:
	Enemy();
	~Enemy();
private:
	POINT m_tPos;
	POINT m_tNewPos;
	int dir = (rand() % 4) + 1;
public:
	void SetPos(int _x, int _y) { m_tPos.x = _x; m_tPos.y = _y; }
	int GetX() { return m_tPos.x; }
	int GetY() { return m_tPos.y; }
public:
	void Update(Stage* stage, Player* player, int idx);
};
