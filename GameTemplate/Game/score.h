#pragma once
#include "GameDelete.h"

class GameSence;

class score : public IGameObject
{
public:

	score();
	~score();

	bool Start();
	void Update();

	GameSence* m_Sence = nullptr;	
	prefab::CFontRender* m_scoreFont = nullptr;				//���Ԃ̃t�H���g
	int Score = 0;				//�N���A��������
	CVector3 m_FontColor = CVector3::One;				//�t�H���g�̕���
	wchar_t ScoreMoji[128];				//������
	CVector2 m_FontPosition = { -200.0f,200.0f };				//�t�H���g�̈ʒu
	GameDelete* m_Delete = nullptr;
};
