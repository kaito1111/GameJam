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
	prefab::CSpriteRender* m_Spritefade = nullptr;	//�t�F�[�h�̊G
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,1.0f };	//�t�F�[�h�̐F
	bool fadein = false;
	bool New = false;
};

