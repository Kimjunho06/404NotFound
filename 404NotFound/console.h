#pragma once
#include <Windows.h>

enum class COLOR {
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VIOLET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE
};

void FullScreen();
void Gotoxy(int, int);
BOOL GotoxyTest(int, int);

void CursorSet(bool, DWORD);
void SetColor(int, int);
int GetCursorYPos();
int GetCursorXPos();

int GetColor();
int GetbgColor();


void fontsize(UINT _weight, UINT _sizex, UINT _sizey);