#pragma once

class buhin;
class Arm;
class ClaftScreen:public IGameObject
{
public:
	ClaftScreen();
	~ClaftScreen();

	bool Start();
	void Update();

	int BuhinCount1 = 0;
	int BuhinCount2 = 0;
	int BuhinCount3 = 0;

	bool Buhin1 = false;
	bool Buhin2 = false;

	void Query();



	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	prefab::CSpriteRender* m_hituyoubuhin1 = nullptr;	//必要な部品の１
	prefab::CSpriteRender* m_hituyoubuhin2 = nullptr;	//必要な部品の２
	prefab::CSkinModelRender* m_BuhinModelRender1 = nullptr;
	CVector3 m_Buhin1pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender2 = nullptr;
	CVector3 m_Buhin2pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender3 = nullptr;
	CVector3 m_Buhin3pos = CVector3::Zero;
	CVector3 m_hozon = CVector3::Zero;
};

