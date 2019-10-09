#include "stdafx.h"
#include "GameSence.h"
#include "Arm.h"
#include "Buckground.h"
#include "result.h"
#include "GameCamera.h"
#include "ClaftScreen.h"
#include "BeltCon.h"

GameSence::GameSence()
{
}

GameSence::~GameSence()
{
	DeleteGO(m_TimerFont);
}

bool GameSence::Start()
{
	NewGO<GameCamera>(0, "gc");
	NewGO<Buckground>(0, "Buckground");
	NewGO<Arm>(0,"Arm");
	NewGO<ClaftScreen>(0, "cs");
	NewGO<BeltCon>(0, "BC");

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"‚ ‚Æ120.0•b");
	m_TimerFont->SetPosition(m_FontPosition);
	m_TimerFont->SetScale(1.5f);

	m_Delete = FindGO<GameDelete>("GameDelete");
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
	if (m_Delete->DeleteGameSence)
	{
		DeleteGO(this);
	}
}
