#pragma once
#include "GameDelete.h"

class buhin;
class Arm;
class ClaftScreen : public IGameObject
{
public:
	ClaftScreen();
	~ClaftScreen();

	bool Start();
	void Update();

	int BuhinCount1 = 0;
	int BuhinCount2 = 0;
	int BuhinCount3 = 0;
	int count = 0;

	float rot1 = 0.0f;	//回転量
	float rot2 = 0.0f;	//回転量


	bool hituyoubuhin1 = false;
	bool hituyoubuhin2 = false;
	bool Buhin1 = false;
	bool Buhin2 = false;
	bool GameOver = false;
	bool senni = false;

	void Query();
	void hituyoubuhin();
	void rotation();
	void claft();
	void sound();

	GameDelete* GD = nullptr;	//デリートするよ！
	CQuaternion qrot = CQuaternion::Identity;
	CQuaternion qRot;	//回転
	CVector3 scale = CVector3::Zero;	//スケール
	CVector3 buhinscale = CVector3::One;	//スケール
	CVector3 buhin1pos = CVector3::Zero;	//必要な部品１の位置
	CVector3 buhin2pos = CVector3::Zero;	//必要な部品２の位置
	prefab::CSpriteRender* m_spriteRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	prefab::CSpriteRender* m_hituyoubuhin1 = nullptr;	//必要な部品の１
	prefab::CSpriteRender* m_hituyoubuhin2 = nullptr;	//必要な部品の２
	prefab::CSkinModelRender* m_BuhinModelRender1 = nullptr;	//右上に表示する部品１
	CVector3 m_Buhin1pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender2 = nullptr;	//右上に表示する部品２
	CVector3 m_Buhin2pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender1_2 = nullptr;	//右上に表示する部品1_2
	CVector3 m_Buhin1_2pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender1_3 = nullptr;	//右上に表示する部品1_3
	CVector3 m_Buhin1_3pos = CVector3::Zero;
	prefab::CSkinModelRender* m_BuhinModelRender1_4 = nullptr;	//右上に表示する部品1_4
	CVector3 m_Buhin1_4pos = CVector3::Zero;
	CVector3 m_hozon = CVector3::Zero;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM用のサウンドソース。
};

