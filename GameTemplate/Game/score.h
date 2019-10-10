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
	prefab::CFontRender* m_scoreFont = nullptr;
	int Score = 0;
	CVector3 m_FontColor = CVector3::One;
	wchar_t ScoreMoji[128];
	CVector2 m_FontPosition = { -200.0f,200.0f };
	GameDelete* m_Delete = nullptr;
};
