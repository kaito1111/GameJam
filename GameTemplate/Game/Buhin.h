#pragma once
#include "Arm.h"
#include "BeltCon.h"
#include "ClaftScreen.h"
class ClaftScreen;
class Buhin : public IGameObject
{
public:
	Buhin();
	~Buhin();
	bool Start();
	void Update();
	void hantei();
	//メンバ変数//
	//仕分け用
	bool IamWheel = false;
	bool Iamframe = false;
	bool IamGomi = false;
	//アームクラス
	Arm* arm;
	//ベルトコンベアクラス
	BeltCon* belt;
	//クラフトスクリーンクラス
	ClaftScreen* CS;
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
	int rand;
};

