#pragma once
#include "define.h"
#include <iostream>

using namespace std;

class Core {
private:
	Core();
	~Core();
public:
	static Core* Instance;
public:
	static Core* GetInst() {
		if (nullptr == Instance)
			Instance = new Core;
		return Instance;
	}
	static void DestroyInst() {
		SAFE_DELETE(Instance);
		/*if (m_pInst) {
			delete m_pInst;
			m_pInst = nullptr;
		}*/
	}
public:
	bool Init();
	int MenuDraw();
	void Run();
};
