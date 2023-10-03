#include <iostream>
#include "MapManager.h"
#include "Stage.h"
#include "define.h"
#include "console.h"
#include "Puzzle.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Enemy.h"

MapManager* MapManager::m_pInst = nullptr;
MapManager::MapManager() {
	for (int i = 0; i < 3; i++)
	{
		m_pStage[i] = nullptr;
	}
}

MapManager::~MapManager()
{
	for (int i = 0; i < 3; i++) {
		SAFE_DELETE(m_pStage[i]);
	}
}

bool MapManager::Init()
{
	char* pFileName[1] = { (char*)"Stage1.txt" };
	for (int i = 0; i < 1; i++) {
		m_pStage[i] = new Stage;
		if (!m_pStage[i]->Init(pFileName[i])) {
			return false;
		}
		if (!puzzle->GetInst()->Init()) {
			return false;
		}
	}
	return true;
}

void MapManager::Run(int _iCurStage)
{
	m_iCurStage = _iCurStage;

	Player* pPlayer = ObjectManager::GetInst()->GetPlayer();
	pPlayer->SetPos(m_pStage[_iCurStage]->GetStart().x, m_pStage[_iCurStage]->GetStart().y);
	for (int i = 0; i < 5; i++) {
		Enemy* pEnemy = ObjectManager::GetInst()->GetEnemy(i);
		pEnemy->SetPos(m_pStage[_iCurStage]->GetSpawner().x, m_pStage[_iCurStage]->GetSpawner().y);
	}
	while (true)
	{
		Gotoxy(0, 0);
		ObjectManager::GetInst()->Update(m_pStage[0]);
		Puzzle::GetInst()->Render();
		m_pStage[m_iCurStage]->Render();
	}
}
