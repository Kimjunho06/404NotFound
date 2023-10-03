#pragma once
#include "define.h"
class Stage;
class Puzzle;
class MapManager
{
private:
	MapManager();
	~MapManager();
private:
	static MapManager* m_pInst;
private:
	Stage* m_pStage[3];
	Puzzle* puzzle;
	int		m_iCurStage;
public:
	Stage* GetStage() { return m_pStage[m_iCurStage]; }
public:
	static MapManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init();
	void Run(int _iCurStage);
};
