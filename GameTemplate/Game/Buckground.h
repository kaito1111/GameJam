#pragma once
class Buckground : public IGameObject
{
public:
	Buckground();
	~Buckground();
	bool Start();
	//�����o�ϐ�//
	prefab::CSpriteRender* m_spriteRender;
	CVector3 m_SpritePos = { 0.0f,0.0f,-1.0f };
	CVector4 m_SpriteColor = { 1.0f,1.0f,1.0f,1.0f };
};

