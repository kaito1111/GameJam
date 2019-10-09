#pragma once

class ClaftScreen;

class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//クレーンのスキンモデル
	ClaftScreen* m_Claft = nullptr;
	CVector3 m_ArmPosition = { 0.0f,200.0f,0.0f };					//クレーンのポジション
	CVector3 m_Scale = CVector3::One;							//クレーンのサイズ
	bool Catch = false;											//つかめたかどうかを判定する
	bool Drop = false;											//謎
	bool Set = true;											//Bボタンを押せるようにする
	float HoldUp = 0.0f;										//つかンで下にいる時間
	float ArmDown = 0.0f;										//下にいつずける時間
};