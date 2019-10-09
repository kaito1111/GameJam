#pragma once

#include "GameSence.h"

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
	wchar_t ScoreMoji[4];

};
