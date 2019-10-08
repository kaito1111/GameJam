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
};

