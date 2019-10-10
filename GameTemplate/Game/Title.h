#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	//メンバ変数//
	//スプライトレンダー
	prefab::CSpriteRender* m_spriteRender;
};

