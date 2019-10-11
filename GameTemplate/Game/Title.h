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
	prefab::CSpriteRender* m_Spritefade = nullptr;	//フェードの絵
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,1.0f };	//フェードの色
	bool fadein = false;
	bool New = false;
};

