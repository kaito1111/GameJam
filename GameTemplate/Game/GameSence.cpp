#include "stdafx.h"
#include "GameSence.h"
#include "Arm.h"
#include "Buckground.h"
#include "GameCamera.h"
#include "ClaftScreen.h"
#include "BeltCon.h"
#include "result.h"

GameSence::GameSence()
{
}

GameSence::~GameSence()
{
	DeleteGO(m_TimerFont);
	DeleteGO(m_Spritefade);
}

bool GameSence::Start()
{
	NewGO<GameCamera>(1, "gc");
	NewGO<Arm>(0, "Arm");
	NewGO<ClaftScreen>(0, "cs");
	NewGO<BeltCon>(0, "BC");
	NewGO<Buckground>(0, "Buckground");

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"����120.0�b");						//���Ԃ̃e�L�X�g���Ăяo��
	m_TimerFont->SetPosition(m_FontPosition);					//�t�H���g�̈ʒu��������
	m_TimerFont->SetScale(1.5f);								//�t�H���g�̃X�P�[�����Z�b�g����

	m_Spritefade = NewGO<prefab::CSpriteRender>(0);
	m_Spritefade->Init(L"sprite/��test.dds", 1280.0f, 720.0f);	//�t�F�[�h�̊G
	m_Spritefade->SetMulColor(m_FadeColor);						//�t�F�[�h�̐F(�����x�j


	m_BGM = NewGO<prefab::CSoundSource>(0);
	m_BGM->Init(L"sound/bgm_kouho1.wav");				//BGM���Z�b�g����
	m_BGM->Play(true);									//BGM�����[�v������
	m_BGM->SetVolume(1.0f);								//BGM�̉��ʂ��Z�b�g����

	m_Arm = FindGO<Arm>("Arm");
	m_Delete = FindGO<GameDelete>("GameDelete");

	return true;
}

void GameSence::Update()
{
	if (m_FadeColor.a <= 0.0f)									//�t�F�[�h�̊G��������ƃQ�[�����n�܂�
	{
		StartGame += GameTime().GetFrameDeltaTime();
		if (StartGame >= 1.0f)									//1�b���ƃA�[������������悤�ɂȂ�
		{
			m_Arm->Drop = true;
		}
		time -= GameTime().GetFrameDeltaTime();					//�Q�[���̃v���C���Ԃ�\������
		swprintf_s(timer, L"����%.1f�b", time);					//���݂̎��Ԃ�ݒ肷��
		m_TimerFont->SetText(timer);							//�e�L�X�g���Z�b�g����
		if (!New) 
		{
			if (time < 0.0f)									//�v���C���Ԃ��[���ɂȂ�΃Q�[�����I������
			{
				NewGO<result>(2, "result");
				GameOver = true;
			}
			New = true;
		}
	}
	m_FadeColor.a -= 0.05f;										//�t�F�[�h�𔖂�����
	m_Spritefade->SetMulColor(m_FadeColor);						//�t�F�[�h�̐F(�����x�j
	if (m_Delete->DeleteGameSence)								//true�ɂȂ�Ǝ���
	{
		DeleteGO(this);
	}
}
