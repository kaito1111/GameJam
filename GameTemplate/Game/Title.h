#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	//�����o�ϐ�//
	//�X�v���C�g�����_�[
	prefab::CSpriteRender* m_spriteRender;
};

