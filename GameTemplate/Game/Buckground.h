#pragma once
class Buckground : public IGameObject
{
public:
	Buckground();
	~Buckground();
	bool Start();
	//�����o�ϐ�//
	prefab::CSpriteRender* m_spriteRender;
};

