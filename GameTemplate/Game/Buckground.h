#pragma once
class Buckground : public IGameObject
{
public:
	Buckground();
	~Buckground();
	bool Start();
	//メンバ変数//
	prefab::CSpriteRender* m_spriteRender;
};

