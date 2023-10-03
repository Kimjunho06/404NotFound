#pragma once
#include "define.h"
#include "Stage.h"
class Player;
class Enemy;
class ObjectManager
{
private:
	ObjectManager();
	~ObjectManager();
private:
	static ObjectManager* m_pInst;
	Player* m_pPlayer;
	Enemy* m_pEnemy[4];
public:
	static ObjectManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new ObjectManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
	Player* GetPlayer() { return m_pPlayer; }
	Enemy* GetEnemy(int idx) { return m_pEnemy[idx]; }
public:
	bool Init();
	void Update(Stage* stage);
};

