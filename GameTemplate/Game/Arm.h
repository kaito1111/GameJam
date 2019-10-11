#pragma once
#include "GameDelete.h"

class ClaftScreen;
class GameSence;

class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//クレーンの腕のスキンモデル
	prefab::CSkinModelRender* m_ArmtumeRight = nullptr;			//クレーンのつめの右のスキンモデル
	prefab::CSkinModelRender* m_ArmtumeLeft = nullptr;			//クレーンのつめの左のスキンモデル
	ClaftScreen* m_Claft = nullptr;
	CVector3 m_ArmPosition = { 50.0f,300.0f,0.0f };				//クレーンのポジション
	CVector3 m_TumePos = CVector3::Zero;						//クレーンのつめのポジション
	CVector3 m_Scale = CVector3::One;							//クレーンのサイズ
	bool Catch = false;											//つかめたかどうかを判定する
	bool Drop = false;											//
	bool Set = true;											//Bボタンを押せるようにする
	float HoldUp = 0.0f;										//つかンで下にいる時間
	float ArmDown = 0.0f;										//下にいつずける時間
	float Rotrate = 0.0f;										//回転率
	bool InitOto = false;										//下に行く音が出る
	CQuaternion m_Rot = CQuaternion::Identity;					//つめを反転させる回転
	GameDelete* m_Delete = nullptr;
	float MoveOto = 0.0f;										//動く音の時間
	bool MoveSound = false;										//動く音が出るフラグ
	GameSence* m_Senne = nullptr;
};