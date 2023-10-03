#include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include "Stage.h"
#include "console.h"
#include "Player.h"
#include "Puzzle.h"
#include "Enemy.h"
#include "ObjectManager.h"

using namespace std;

Stage::Stage() : m_tStart{}, m_tEnd{}, m_cStage{} {}

Stage::~Stage()
{
}

bool Stage::Init(const char* _pFilename)
{
	ifstream readFile;
	if (readFile.is_open())
		return false;
	readFile.open(_pFilename);
	for (int i = 0; i < MAP_Y; i++) {
		readFile.clear();
		// 1: 담을 곳 / 2. 스트림사이즈
		readFile.getline(m_cStage[i], MAP_X + 1);
		for (int j = 0; j < MAP_X; j++) {
			if (m_cStage[i][j] == (char)STAGE_TYPE::START) {
				m_tStart.x = j;
				m_tStart.y = i;
			}
			if (m_cStage[i][j] == (char)STAGE_TYPE::END) {
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
			if (m_cStage[i][j] == (char)STAGE_TYPE::ENEMYSPAWNER) {
				m_tSpawner.x = j;
				m_tSpawner.y = i;
			}
		}
	}
	return true;
}

void Stage::Render()
{
	Player* pPlayer = ObjectManager::GetInst()->GetPlayer();
	int iPlayerx = pPlayer->GetX();
	int iPlayery = pPlayer->GetY();
	
	vector<POINT> v;
	for (int i = 0; i < 5; i++)
	{
		Enemy* pEnemy = ObjectManager::GetInst()->GetEnemy(i);
		v.push_back({pEnemy->GetX(), pEnemy->GetY()});
	}
	int random = rand() % 15 + 1;

	for (int i = 0; i < MAP_Y; i++) {
		for (int j = 0; j < MAP_X; j++) {
			Gotoxy(20 + j, 15 + i);
			if (i == iPlayery && j == iPlayerx) {
				SetColor((int)COLOR::GRAY, (int)COLOR::BLUE);
				cout << "§";
			}
			bool drawed = false;
			for (int k = 0; k < 5; k++) {
				if (i == v[k].y && j == v[k].x) {
					SetColor((int)COLOR::GRAY, (int)COLOR::RED);
					cout << "Æ";
					drawed = true;
					break;
				}
			}
			if (drawed) continue;
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			if (m_cStage[i][j] == (char)STAGE_TYPE::ROAD) {
				cout << "  ";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::WALL) {
				SetColor(random, (int)COLOR::BLACK);
				cout << "■";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::START) {
				int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"‡";
				int iDefmode = _setmode(_fileno(stdout), iUnimode);
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::END) {
				int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);
				SetColor(random , random - 1);
				wcout << L"Ħ";
				int iDefmode = _setmode(_fileno(stdout), iUnimode);
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::COIN) {
				int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"⊙";
				int iDefmode = _setmode(_fileno(stdout), iUnimode);
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::ENEMYSPAWNER) {
				int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);
				wcout << L"†";
				int iDefmode = _setmode(_fileno(stdout), iUnimode);
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << endl;
	}

	Gotoxy(20, 40);
	cout << "Score : " + to_string(score * 100);
	Gotoxy(20, 41);
	cout << "ClearPercent : " + to_string(Puzzle::GetInst()->_clearPercent) + "% / 100%          ";
}

void Stage::Update()
{
}
