#include <iostream>
#include <Windows.h>
#include "Core.h"

using namespace std;

int main() {
	// Core(GameManager) 초기화
	if (!Core::GetInst()->Init()) {
		// 종료
		system("cls");
		cout << "게임 초기화 실패!" << endl;
		Core::DestroyInst();
		return 0;
	}
	// Core(GameManager) 게임 구동
	Core::GetInst()->Run();

	// Core(GameManager) 끄기
	Core::DestroyInst();
}