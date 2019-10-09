#include "stdafx.h"
#include "GameSence.h"
#include "Game.h"
#include "Arm.h"
#include "Buckground.h"
#include "result.h"

GameSence::GameSence()
{
}

GameSence::~GameSence()
{
}

bool GameSence::Start()
{
	NewGO<Game>(0,"Game");
	NewGO<Arm>(0,"Arm");
	NewGO<Buckground>(0, "Buckground");

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"‚ ‚Æ120.0•b");
	m_TimerFont->SetPosition(m_FontPosition);
	m_TimerFont->SetScale(1.5f);
	return true;
}

void GameSence::Update()
{
	time -= GameTime().GetFrameDeltaTime();
	swprintf_s(timer, L"‚ ‚Æ%.1f•b", time);
	m_TimerFont->SetText(timer);
	if (!New) {
		if (time < 0.0f)
		{
			NewGO<result>(0, "result");
			GameOver = true;

		}
		New = true;
	}
}
