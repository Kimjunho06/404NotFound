#pragma once
#include "define.h"

class InOutScene
{
private:
	InOutScene();
	~InOutScene();
private:
	static InOutScene* m_pInst;
public:
	static InOutScene* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new InOutScene;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	void Die();
	void Clear();
};
