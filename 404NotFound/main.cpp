#include <iostream>
#include <Windows.h>
#include "Core.h"

using namespace std;

int main() {
	// Core(GameManager) �ʱ�ȭ
	if (!Core::GetInst()->Init()) {
		// ����
		system("cls");
		cout << "���� �ʱ�ȭ ����!" << endl;
		Core::DestroyInst();
		return 0;
	}
	// Core(GameManager) ���� ����
	Core::GetInst()->Run();

	// Core(GameManager) ����
	Core::DestroyInst();
}