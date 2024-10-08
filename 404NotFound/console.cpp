#include "console.h"

void FullScreen() {
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

void Gotoxy(int x, int y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x * 2, y };

	SetConsoleCursorPosition(hOut, Cur);
}

BOOL GotoxyTest(int x, int y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x * 2, y };

	return SetConsoleCursorPosition(hOut, Cur);
}

void CursorSet(bool _bVis, DWORD _dwSize)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.bVisible = _bVis;
	Curinfo.dwSize = _dwSize;

	SetConsoleCursorInfo(hOut, &Curinfo);
}

void SetColor(int _color, int _bgcolor)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, (_bgcolor << 4) | _color);
}

int GetCursorYPos()
{
	POINT pt = {};
	GetCursorPos(&pt);
	
	return pt.y;
}

int GetCursorXPos()
{
	POINT pt = {};
	GetCursorPos(&pt);

	return pt.x;
}

int GetColor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(hOut, &info);
	int color = info.wAttributes & 0xf;

	return color;
}

int GetbgColor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(hOut, &info);
	int bgcolor = (info.wAttributes & 0xf) >> 4;

	return bgcolor;
}

void fontsize(UINT _weight, UINT _sizex, UINT _sizey)
{
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizex;
	font.dwFontSize.Y = _sizey;
	SetCurrentConsoleFontEx(hout, false, &font);
}


