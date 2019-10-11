#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSence.h"
#include "GameDelete.h"

Title::Title()
{

}
Title::~Title()
{
	//�^�C�g���������ꂽ��폜
	DeleteGO(m_spriteRender);
	DeleteGO(m_Spritefade);
}
bool::Title::Start()
{

	m_Spritefade = NewGO<prefab::CSpriteRender>(2);
	m_Spritefade->Init(L"sprite/��test.dds", 1280.0f, 720.0f);	//�t�F�[�h�̊G
	m_Spritefade->SetMulColor(m_FadeColor);						//�t�F�[�h�̐F(�����x�j
	//�C���X�^���X
	m_spriteRender = NewGO<prefab::CSpriteRender>(3);
	//�^�C�g���̓ǂݍ���
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
	return true;
}

void Title::Update()
{
	//�L�[�{�[�h��K�ŋN��
	//�Q�[�����[�v�͂��Ȃ��̂Ō�ŏC��

	if (fadein)
	{
		m_FadeColor.a -= 0.05f;										//�t�F�[�h�𔖂�����
	}
	if (m_FadeColor.a <= 0.0f)
	{
		DeleteGO(this);
	}
	
	
	m_Spritefade->SetMulColor(m_FadeColor);						//�t�F�[�h�̐F(�����x�j
	m_Spritefade->SetMulColor(m_FadeColor);						//�t�F�[�h�̐F(�����x�j
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<GameDelete>(0,"GameDelete");
		NewGO<GameSence>(0,"GameSence");
		fadein = true;
	}
}
