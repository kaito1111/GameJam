#pragma once
class BeltCon : public IGameObject
{
public:
	BeltCon();
	~BeltCon();
	bool Start();
	void Update();
	//メンバ変数//
	//モデルレンダー
	prefab::CSkinModelRender* m_skinModelRender;
	//スケール
	CVector3 scale;
	//座標
	CVector3 m_position = CVector3::Zero;
	//タイマー
	float m_timer = 0;
	int rand = 0;
};

