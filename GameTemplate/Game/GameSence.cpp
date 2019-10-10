#include "stdafx.h"
#include "GameSence.h"
#include "Arm.h"
#include "Buckground.h"
#include "GameCamera.h"
#include "ClaftScreen.h"
#include "BeltCon.h"
#include "result.h"

GameSence::GameSence()
{
}

GameSence::~GameSence()
{
	DeleteGO(m_TimerFont);
	DeleteGO(m_Spritefade);
	DeleteGO(m_Arm);
	DeleteGO(m_BGM);
}

bool GameSence::Start()
{
	NewGO<GameCamera>(1, "gc");
	NewGO<Arm>(0, "Arm");
	NewGO<ClaftScreen>(0, "cs");
	NewGO<BeltCon>(0, "BC");
	NewGO<Buckground>(0, "Buckground");

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"‚ ‚Æ120.0•b");
	m_TimerFont->SetPosition(m_FontPosition);
	m_TimerFont->SetScale(1.5f);

	m_Spritefade = NewGO<prefab::CSpriteRender>(0);
	m_Spritefade->Init(L"sprite/‹ótest.dds", 1280.0f, 720.0f);
	m_Spritefade->SetMulColor(m_FadeColor);


	m_BGM = NewGO<prefab::CSoundSource>(0);
	m_BGM->Init(L"sound/bgm_kakutei.wav");
	m_BGM->Play(true);
	m_BGM->SetVolume(1.0f);

	m_Delete = FindGO<GameDelete>("GameDelete");
	return true;
}

void GameSence::Update()
{
	if (m_FadeColor.a <= 0.0f)
	{
		StartGame += GameTime().GetFrameDeltaTime();
		if (StartGame >= 1.0f)
		{
			if (!move)
			{
				m_Arm = FindGO<Arm>("Arm");
				m_Arm->Drop = true;
				move = true;
			}
		}
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
	m_FadeColor.a -= 0.05f;
	m_Spritefade->SetMulColor(m_FadeColor);
	if (m_Delete->DeleteGameSence)
	{
		DeleteGO(this);
	}
}
