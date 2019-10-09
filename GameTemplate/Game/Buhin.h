#pragma once
#include "Arm.h"
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
	//モデルレンダー
	prefab::CSkinModelRender* m_skinModelRender;
	//部品の座標
	CVector3 m_position = CVector3::Zero;
	//流れる速さ
	CVector3 m_moveSpeed = CVector3::Zero;
};

