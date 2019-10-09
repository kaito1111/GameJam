#pragma once
#include "Arm.h"
#include "Buhin.h"

class ClaftScreen:public IGameObject
{
public:
	ClaftScreen();
	~ClaftScreen();

	bool Start();
	void Update();

	int ClaftCount = 0;	//アームが画面外に行ったら１にする
	int BuhinCount1 = 0;
	int BuhinCount2 = 0;
	int BuhinCount3 = 0;

	bool Buhin1 = false;
	bool Buhin2 = false;

	void Query();

	Arm* arm = nullptr;	//アーム
	Buhin* buhin1 = nullptr;	//部品1
	Buhin* buhin2 = nullptr;	//部品2
	Buhin* buhin3 = nullptr;	//部品3

	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender1 = nullptr;
	CVector3 m_Buhin1pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender2 = nullptr;
	CVector3 m_Buhin2pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender3 = nullptr;
	CVector3 m_Buhin3pos = CVector3::Zero;
};

