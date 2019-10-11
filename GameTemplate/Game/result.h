#pragma once
#include "GameDelete.h"
class result : public IGameObject
{
public:
	result();
	~result();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_SpriteTitle = nullptr;					//�^�C�g���֖߂�G
	prefab::CSpriteRender* m_SpriteReStart = nullptr;				//���X�^�[�g����G
	prefab::CSpriteRender* m_SpriteSelect = nullptr;				//�I������G
	CVector3 m_TitlePosition = { -300.0f,-300.0f,0.0f };			//�^�C�g���̃|�W�V����
	CVector3 m_ReStartPosition = { 300.0f,-300.0f,0.0f };			//���X�^�[�g�̃|�W�V����
	CVector3 m_SelectPosition= { -300.0f,-300.0f,0.0f };			//�I������|�W�V����
	float SpriteGO = 0.0f;				//�G���\��������܂ł̎���
	bool New = false;				//�GNewGO�����
	prefab::CSpriteRender* m_Spritefade = nullptr;				//�t�F�[�h�̊G
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,0.0f };				//�t�F�[�h�̃J���[
	bool fadeout = false;				//�t�F�[�h�̊G���Z�b�g����G
	bool restart = false;
	bool title = false;
	bool Newgo = false;

	GameDelete* m_GameDelete = nullptr;
};