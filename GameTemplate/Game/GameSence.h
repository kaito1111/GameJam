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

	prefab::CFontRender* m_TimerFont = nullptr;		//���Ԃ̃t�H���g
	CVector2 m_FontPosition = { -600.0f,300.0f };	//�t�H���g�̕���
	CVector4 m_Color = CVector4::White;				//�t�H���g�̃J���[
	wchar_t timer[128];
	float time = 30.0f;
	bool New = false;								//���U���g���o����
	bool GameOver = false;							//�Q�[���������I�ɏI�������
	GameDelete* m_Delete = nullptr;					
	float StartGame = 0.0f; 						//�Q�[�����n�܂�
	Arm* m_Arm = nullptr;
	prefab::CSoundSource* m_BGM = nullptr;			//BGM���o��
};
