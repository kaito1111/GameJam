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
}
bool::Title::Start()
{
	//�C���X�^���X
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g���̓ǂݍ���
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
	return true;
}

void Title::Update()
{
	//�L�[�{�[�h��K�ŋN��
	//�Q�[�����[�v�͂��Ȃ��̂Ō�ŏC��
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<GameDelete>(0,"GameDelete");
		NewGO<GameSence>(0,"GameSence");
		DeleteGO(this);
	}
}
