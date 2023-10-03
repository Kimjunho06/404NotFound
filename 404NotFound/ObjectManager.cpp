#include "ObjectManager.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
ObjectManager* ObjectManager::m_pInst = nullptr;
ObjectManager::ObjectManager()
    : m_pPlayer(nullptr)
{
    for (int i = 0; i < 5; i++) {
        m_pEnemy[i] = nullptr;
    }
}

ObjectManager::~ObjectManager()
{
    SAFE_DELETE(m_pPlayer);
    for (int i = 0; i < 5; i++) {
        SAFE_DELETE(m_pEnemy[i]);
    }
}

bool ObjectManager::Init()
{
    m_pPlayer = new Player;
    for (int i = 0; i < 5; i++) {
        m_pEnemy[i] = new Enemy;
    }
    
    return true;
}

void ObjectManager::Update(Stage* stage)
{
    m_pPlayer->Update(stage);
    for (int i = 0; i < 5; i++) { 
        m_pEnemy[i]->Update(stage, m_pPlayer, i);
    }
}

