#pragma once
#include "GameDelete.h"
#include "ClaftScreen.h"
class GameSence;

class score : public IGameObject
{
public:

	score();
	~score();

	bool Start();
	void Update();
	int hozon = 0.0f;

	ClaftScreen* CS = nullptr;	//�N���t�g�X�N���[��

	prefab::CFontRender* m_scoreFont = nullptr;					//���Ԃ̃t�H���g
	int Score = 0;												//�N���A��������
	CVector3 m_FontColor = CVector3::One;						//�t�H���g�̕���
	wchar_t ScoreMoji[128];										//������
	CVector2 m_FontPosition = { -200.0f,200.0f };				//�t�H���g�̈ʒu
	float Setscore = 0.0f;										//�X�R�A���o�Ă��鎞��
	GameDelete* m_Delete = nullptr;
	GameSence* m_Sence = nullptr;
};
