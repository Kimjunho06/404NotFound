#include <algorithm>
#include <conio.h>
#include "Player.h"
#include "Stage.h"
#include "define.h"
#include "Puzzle.h"
#include<iostream>
Player::Player()
	: m_tPos{ 1,2 }
{
}

Player::~Player()
{
}

void Player::Update(Stage* stage)
{	
	m_tNewPos = m_tPos;
	
	clock_t curtime, oldtime;
	oldtime = clock();
	Puzzle::GetInst()->Update();

	while (true)
	{
		curtime = clock();

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			if (stage->m_cStage[m_tPos.y - 1][m_tPos.x] != '1') {
				dir = 'W';
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (stage->m_cStage[m_tPos.y + 1][m_tPos.x] != '1') {
				dir = 'S';
			}
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			if (stage->m_cStage[m_tPos.y][m_tPos.x-1] != '1') {
				dir = 'A';
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			if (stage->m_cStage[m_tPos.y][m_tPos.x+1] != '1') {
				dir = 'D';
			}
		}
		

		if (curtime - oldtime > 10)
		{
			if (stage->m_cStage[m_tPos.y][m_tPos.x] == (char)STAGE_TYPE::END) {
				if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
					if (Puzzle::GetInst()->starPos.x >= Puzzle::GetInst()->checkPos[0].x - 2	&&Puzzle::GetInst()->starPos.x <= Puzzle::GetInst()->checkPos[0].x + 2) {
						Puzzle::GetInst()->_clearPercent += 10;
					}
					else {
						if (Puzzle::GetInst()->_clearPercent <= 0) return;
						Puzzle::GetInst()->_clearPercent -= 5;
					}
				}
			}
			switch (dir)
			{
			case 'W':
				--m_tNewPos.y;
				break;
			case 'S':
				++m_tNewPos.y;
				break;
			case 'A':
				--m_tNewPos.x;
				break;
			case 'D':
				++m_tNewPos.x;
				break;
			}

			m_tNewPos.x = std::clamp((int)m_tNewPos.x, 1, MAP_X - 2);
			m_tNewPos.y = std::clamp((int)m_tNewPos.y, 1, MAP_Y - 2);

			if (stage->m_cStage[m_tNewPos.y][m_tNewPos.x] != '1') {
				m_tPos = m_tNewPos;
			}

			if (stage->m_cStage[m_tPos.y][m_tPos.x] == (char)STAGE_TYPE::COIN) {
				int score = stage->GetScore();
				stage->SetScore(++score);
				stage->m_cStage[m_tPos.y][m_tPos.x] = (char)STAGE_TYPE::ROAD;
			}


			oldtime = curtime;
			break;
		}
	}
}
/*
11111111111111111111111111111111111111111111111111
12444444444444444444444444444444444444444444444441
14141111114111111111111111111111111114141414144441
14141444444444444444444444444444444444141414111141
14141111114111111111111111111111111114141414144441
14141414444410444444444444444444444444141414144141
14141414141410111111111111111111111414141414144141
14141414141410000000144414441444444414141414441141
14141414141410000000141444144144144414141414144141
14141414141410000000141411111144141414141414114141
14141414141000000000041414444444141414141414144141
14141414141111000000141414414141111414141414144141
14141444444444000000141444414444444444441414114141
14141414141414141111111111111111111414111414144141
14141414141414141444444444444444441414141414444141
14141414141414141411111111111111141414141414114141
14141414141414141444441444111444141414141414144141
14141414141414141414141414141414141414141414144141
14141414141414141414141414141414141414141414144141
14141414141414141414141414144414141414141414144141
14141414141414141414141414111414141411141414141141
14141414141414144414141414141414141444441444144441
14141111141444111414141414141414141414111111111141
14144444444414444414144414141414444414444444444431
11111111111111111111111111111111111111111111111111

*/