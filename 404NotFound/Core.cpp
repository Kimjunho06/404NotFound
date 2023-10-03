#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <vector>
#include <mmsystem.h>
#include "core.h"
#include "console.h"
#include "MapManager.h"
#include "ObjectManager.h"
#include "resource.h"

using namespace std;

Core* Core::Instance = nullptr;

Core::Core() {

}

Core::~Core()
{
}

bool Core::Init()
{
	if (!MapManager::GetInst()->Init()) {
		return false;
	}
	if (!ObjectManager::GetInst()->Init())
		return false;


	FullScreen();
	SetConsoleTitle(L"404 Not Found!");
	CursorSet(false, 1);
	return true;
}

void Core::Run()
{
	PlaySound(TEXT("openBgm.wav"), NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
	int iStage = MenuDraw();
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC | SND_LOOP);
	
	if (iStage == 0) return;
	else if (iStage == 1) 
	{
		system("cls");

		MapManager::GetInst()->Run(iStage - 1);
	}

}

int Core::MenuDraw()
{
	int cnt = 0;
	int y = 10;

	int iUnimode = _setmode(_fileno(stdout), _O_U16TEXT);

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	wcout << L"	██╗  ██╗ ██████╗ ██╗  ██╗    ███╗   ██╗ ██████╗ ████████╗    ███████╗ ██████╗ ██╗   ██╗███╗   ██╗██████╗ ██╗ " << endl;
	wcout << L"	██║  ██║██╔═████╗██║  ██║    ████╗  ██║██╔═══██╗╚══██╔══╝    ██╔════╝██╔═══██╗██║   ██║████╗  ██║██╔══██╗██║ " << endl;
	wcout << L"	███████║██║██╔██║███████║    ██╔██╗ ██║██║   ██║   ██║       █████╗  ██║   ██║██║   ██║██╔██╗ ██║██║  ██║██║ " << endl;
	wcout << L"	╚════██║████╔╝██║╚════██║    ██║╚██╗██║██║   ██║   ██║       ██╔══╝  ██║   ██║██║   ██║██║╚██╗██║██║  ██║╚═╝ " << endl;
	wcout << L"	     ██║╚██████╔╝     ██║    ██║ ╚████║╚██████╔╝   ██║       ██║     ╚██████╔╝╚██████╔╝██║ ╚████║██████╔╝██╗ " << endl;
	wcout << L"	     ╚═╝ ╚═════╝      ╚═╝    ╚═╝  ╚═══╝ ╚═════╝    ╚═╝       ╚═╝      ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚═════╝ ╚═╝ " << endl;
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	Gotoxy(0, y);
	wcout << L" ╔═╗┌─┐┌┬┐┌─┐  ╔═╗┌┬┐┌─┐┬─┐┌┬┐┬ " << endl;
	wcout << L" ║ ╦├─┤│││├┤   ╚═╗ │ ├─┤├┬┘ │ │ " << endl;
	wcout << L" ╚═╝┴ ┴┴ ┴└─┘  ╚═╝ ┴ ┴ ┴┴└─ ┴ o " << endl;
	Gotoxy(0, y + 4);
	wcout << L" ╔═╗ ┬ ┬┬┌┬┐ " << endl;
	wcout << L" ║═╬╗│ ││ │  " << endl;
	wcout << L" ╚═╝╚└─┘┴ ┴  " << endl;

	
	int iDefmode = _setmode(_fileno(stdout), iUnimode);

	while (true)
	{
		int mouseYPos = GetCursorYPos();
		int mouseXPos = GetCursorXPos();

		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) {
			if (mouseYPos > 185 && mouseYPos < 225) {
				if (mouseXPos > 0 && mouseXPos < 260) {
					return 1;
				}
			}
			else if (mouseYPos > 250 && mouseYPos < 290){
				if (mouseXPos > 0 && mouseXPos < 100) {
					return 0;
				}
			}
		}
	}
	cout << "break;";
	return 0;
}
