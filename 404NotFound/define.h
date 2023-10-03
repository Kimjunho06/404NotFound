#pragma once
#include <Windows.h>
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}

const int MAP_X = 50;
const int MAP_Y = 25;

const int STAR_X = 21;
const int STAR_Y = 13;

enum class STAGE_TYPE
{
	ROAD = '0',
	WALL = '1',
	START = '2',
	END = '3',
	COIN = '4',
	ENEMYSPAWNER = '5'
};

enum class IMAGE_TYPE {
	EMPTY = '0',
	WALL = '1',
	OUTLINE = '2',
	CHECKPOINT = '3'

};