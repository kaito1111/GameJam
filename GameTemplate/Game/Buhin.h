#pragma once
#include "Arm.h"
#include "BeltCon.h"
class ClaftScreen;
class Buhin : public IGameObject
{
public:
	Buhin();
	~Buhin();
	bool Start();
	void Update();
	//メンバ変数//
	//クラス変数
	Arm* arm;
	//クラス変数
	BeltCon* belt;
	//モデルレンダー
	prefab::CSkinModelRender* m_skinModelRender;
	//つかまれた判定
	bool IsCatch = false;
	//クオータニオン
	CQuaternion qRot = CQuaternion::Identity;
	//部品の座標
	CVector3 m_position = CVector3::Zero;
	//流れる速さ
	CVector3 m_moveSpeed = CVector3::Zero;
	bool IamGomi = false;
};

