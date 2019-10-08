#pragma once
class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//クレーンのスキンモデル
	CVector3 m_ArmPosition = CVector3::Zero;					//クレーンのポジション
	CVector3 m_Scale = CVector3::One;							//クレーンのサイズ
	bool Catch = false;											//つかめたかどうかを判定する

};