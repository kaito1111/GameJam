#include "stdafx.h"
#include "Title.h"
#include "Game.h"

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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
	//�C���X�^���X
>>>>>>> bcead7dfc736d1bfcb895de0c8d11c7ddbae7f91
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//�^�C�g���̓ǂݍ���
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
>>>>>>> c3538f83b0fe02d377ab840b9941d9312304d0df
	return true;
}

void Title::Update()
{
	//�L�[�{�[�h��K�ŋN��
	//�Q�[�����[�v�͂��Ȃ��̂Ō�ŏC��
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<Game>(0);
		DeleteGO(this);
	}
}
