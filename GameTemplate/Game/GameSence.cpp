#include "stdafx.h"
#include "GameSence.h"
#include "Game.h"
#include "Arm.h"
#include "result.h"

GameSence::GameSence()
{
}

GameSence::~GameSence()
{
}

bool GameSence::Start()
{
	NewGO<Game>(0);
	NewGO<Arm>(0);

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"‚ ‚Æ120.0•b");
	return true;
}

void GameSence::Update()
{
	time -= GameTime().GetFrameDeltaTime();
	swprintf_s(timer, L"‚ ‚Æ%f.1•b", time);
	if (time < 0.0f)
	{
		NewGO<result>(0);
	}
}
