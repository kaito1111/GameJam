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
	//乱数　Buhinクラスで使用するので.hで定義
	int rand = 0;
	//waru と waruh の値をいじるとゴミがでる割合を変えれます
	int waru = 8;
	//waruhは初期化用なのでcpp変更しないでください。
	int waruh = 8;
};

