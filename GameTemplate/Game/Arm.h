#pragma once
class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//クレーンのスキンモデル
	CVector3 m_ArmPosition = { 0.0f,200.0f,0.0f };					//クレーンのポジション
	CVector3 m_Scale = CVector3::One;							//クレーンのサイズ
	bool Catch = false;											//つかめたかどうかを判定する
	bool Drop = false;
};