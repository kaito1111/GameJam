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
}

bool GameSence::Start()
{
	NewGO<GameCamera>(1, "gc");
	NewGO<Arm>(0, "Arm");
	NewGO<ClaftScreen>(0, "cs");
	NewGO<BeltCon>(0, "BC");
	NewGO<Buckground>(0, "Buckground");

	m_TimerFont = NewGO<prefab::CFontRender>(0);
	m_TimerFont->SetText(L"あと120.0秒");						//時間のテキストを呼び出す
	m_TimerFont->SetPosition(m_FontPosition);					//フォントの位置を教える
	m_TimerFont->SetScale(1.5f);								//フォントのスケールをセットする

	m_Spritefade = NewGO<prefab::CSpriteRender>(0);
	m_Spritefade->Init(L"sprite/空test.dds", 1280.0f, 720.0f);	//フェードの絵
	m_Spritefade->SetMulColor(m_FadeColor);						//フェードの色(透明度）


	m_BGM = NewGO<prefab::CSoundSource>(0);
	m_BGM->Init(L"sound/bgm_kouho1.wav");				//BGMをセットする
	m_BGM->Play(true);									//BGMをループさせる
	m_BGM->SetVolume(1.0f);								//BGMの音量をセットする

	m_Arm = FindGO<Arm>("Arm");
	m_Delete = FindGO<GameDelete>("GameDelete");

	return true;
}

void GameSence::Update()
{
	if (m_FadeColor.a <= 0.0f)									//フェードの絵が消えるとゲームが始まる
	{
		StartGame += GameTime().GetFrameDeltaTime();
		if (StartGame >= 1.0f)									//1秒立つとアームが動かせるようになる
		{
			m_Arm->Drop = true;
		}
		time -= GameTime().GetFrameDeltaTime();					//ゲームのプレイ時間を表示する
		swprintf_s(timer, L"あと%.1f秒", time);					//現在の時間を設定する
		m_TimerFont->SetText(timer);							//テキストをセットする
		if (!New) 
		{
			if (time < 0.0f)									//プレイ時間がゼロになればゲームが終了する
			{
				NewGO<result>(2, "result");
				GameOver = true;
			}
			New = true;
		}
	}
	m_FadeColor.a -= 0.05f;										//フェードを薄くする
	m_Spritefade->SetMulColor(m_FadeColor);						//フェードの色(透明度）
	if (m_Delete->DeleteGameSence)								//trueになると死ぬ
	{
		DeleteGO(this);
	}
}
