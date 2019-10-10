#pragma once
#include "GameDelete.h"
class Arm;
class GameSence : public IGameObject
{
public:

	GameSence();
	~GameSence();

	bool Start();
	void Update();

	prefab::CFontRender* m_TimerFont = nullptr;						//���Ԃ̃t�H���g
	CVector2 m_FontPosition = { -600.0f,300.0f };					//�t�H���g�̕���
	CVector4 m_Color = CVector4::White;					//�t�H���g�̃J���[
	wchar_t timer[128];
	float time = 120.0f;
	bool New = false;					//
	bool GameOver = false;					//
	GameDelete* m_Delete = nullptr;					
	prefab::CSpriteRender* m_Spritefade = nullptr;					//�t�F�[�h�̊G
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,1.0f };					//�t�F�[�h�̐F
	float StartGame = 0.0f; 					//�Q�[�����n�܂�
	Arm* m_Arm = nullptr;
	bool move = false; 					//�A�[���𓮂����̂�������
	prefab::CSoundSource* m_BGM = nullptr;					//BGM���o��
};
