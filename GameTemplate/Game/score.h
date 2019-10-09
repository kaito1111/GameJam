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
	int Score = 0;
};
