#include <algorithm>
#include <time.h>
#include <iostream>
#include "Enemy.h"
#include "Player.h"
#include "Stage.h"
#include "ObjectManager.h"
#include "InOutScene.h"

Enemy::Enemy()
	: m_tPos{ 0,0 }
{
}

Enemy::~Enemy()
{
}

void Enemy::Update(Stage* stage, Player* player, int idx)
{
	srand((unsigned int)time(NULL));
	
	m_tNewPos = m_tPos;

	switch (dir)
	{
	case 1:
		--m_tNewPos.y;
		break;
	case 2:
		++m_tNewPos.y;
		break;
	case 3:
		--m_tNewPos.x;
		break;
	case 4:
		++m_tNewPos.x;
		break;
	default:
		break;
	}
	
	if (m_tNewPos.y == MAP_Y - 1 || m_tNewPos.x == MAP_X-1) {
		dir = (rand() % 4) + 1;
		return;
	}
	else if (m_tNewPos.y == 0 || m_tNewPos.x == 0) {
		dir = (rand() % 4) + 1;
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (i == idx) continue;
		if (m_tNewPos.x == ObjectManager::GetInst()->GetEnemy(i)->GetX() && m_tNewPos.y == ObjectManager::GetInst()->GetEnemy(i)->GetY()) {
			dir = (rand() % 4) + 1;
			return;
		}
	}


	m_tNewPos.x = std::clamp((int)m_tNewPos.x, 1, MAP_X - 2);
	m_tNewPos.y = std::clamp((int)m_tNewPos.y, 1, MAP_Y - 2);
	

	if (m_tPos.x == player->GetX() && m_tPos.y == player->GetY()) {
		system("cls");
		InOutScene::GetInst()->Die();
		exit(0);
	}
	if (m_tNewPos.x == player->GetX() && m_tNewPos.y == player->GetY()) {
		system("cls");
		InOutScene::GetInst()->Die();
		exit(0);
	}

	/*for (int i = 0; i < 5; i++) {
		if (i == idx) continue;
		if (m_tNewPos.x == ObjectManager::GetInst()->GetEnemy(i)->GetX() 
			&& m_tNewPos.y == ObjectManager::GetInst()->GetEnemy(i)->GetY()) 
		{

		}
	}*/

	if (stage->m_cStage[m_tNewPos.y][m_tNewPos.x] == (char)STAGE_TYPE::WALL) {
		dir = (rand() % 4) + 1;
		return;
	}
	else if (stage->m_cStage[m_tNewPos.y][m_tNewPos.x] != (char)STAGE_TYPE::WALL) {
		m_tPos = m_tNewPos;
	}
	
	Sleep(10);
	
}
