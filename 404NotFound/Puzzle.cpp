#include <fstream>
#include <iostream>
#include <time.h>
#include "Puzzle.h"
#include "Player.h"
#include "Stage.h"
#include "console.h"
#include "InOutScene.h"
#include "define.h"

using namespace std;

Puzzle* Puzzle::m_pInst = nullptr;
Puzzle::Puzzle() : starPos({2, 11}), dir(1)
{
}

Puzzle::~Puzzle()
{

}

bool Puzzle::Init()
{
	ifstream readFile;
	if (readFile.is_open())
		return false;
	readFile.open("StarPos.txt");
	for (int i = 0; i < STAR_Y; i++) {
		readFile.clear();
		// 1: 담을 곳 / 2. 스트림사이즈
		readFile.getline(map[i], STAR_X + 1);
		for (int j = 0; j < STAR_X; j++) {
			if (map[i][j] == (char)IMAGE_TYPE::CHECKPOINT) {
				checkPos.push_back({j, i});
			}
		}
	}
	dir = 1;
}

void Puzzle::Update()
{	
	Gotoxy(0, 0);
	if (starPos.x == 1 || starPos.x == STAR_X-2) {
		dir *= -1;
		//starPos.x += dir;
	}
	starPos.x += dir;
	if (_clearPercent >= 100) {
		system("cls");
		InOutScene::GetInst()->Clear();
		exit(0);
	}
	//x = 625~825, y = 235~245
}

void Puzzle::Render()
{
	for (int i = 0; i < STAR_Y; i++) {
		for (int j = 0; j < STAR_X; j++) {
			Gotoxy(35 + j, i);
			if (i == starPos.y && j == starPos.x) {
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::YELLOW);
				cout << "★";
			}
			if (map[i][j] == (char)IMAGE_TYPE::EMPTY) {
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::YELLOW);
				cout << "  ";
			}
			else if (map[i][j] == (char)IMAGE_TYPE::WALL) {
				SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::LIGHT_YELLOW);
				cout << "■";
			}
			else if (map[i][j] == (char)IMAGE_TYPE::CHECKPOINT) {
				SetColor((int)COLOR::RED, (int)COLOR::YELLOW);
				cout << "■";
			}
			else if (map[i][j] == (char)IMAGE_TYPE::OUTLINE) {
				SetColor((int)COLOR::LIGHT_GRAY, (int)COLOR::LIGHT_GRAY);
				cout << "■";
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << endl;
	}
	Gotoxy(35, 13);
	cout << "Cross then.. Press! Space bar for 1 second";
	
}