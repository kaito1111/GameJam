#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSence.h"
#include "GameDelete.h"

Title::Title()
{

}
Title::~Title()
{
	//タイトルが消されたら削除
	DeleteGO(m_spriteRender);
	DeleteGO(m_Spritefade);
}
bool::Title::Start()
{

	m_Spritefade = NewGO<prefab::CSpriteRender>(2);
	m_Spritefade->Init(L"sprite/空test.dds", 1280.0f, 720.0f);	//フェードの絵
	m_Spritefade->SetMulColor(m_FadeColor);						//フェードの色(透明度）
	//インスタンス
	m_spriteRender = NewGO<prefab::CSpriteRender>(3);
	//タイトルの読み込み
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
	return true;
}

void Title::Update()
{
	//キーボードのKで起動
	//ゲームループはしないので後で修正

	if (fadein)
	{
		m_FadeColor.a -= 0.05f;										//フェードを薄くする
	}
	if (m_FadeColor.a <= 0.0f)
	{
		DeleteGO(this);
	}
	
	
	m_Spritefade->SetMulColor(m_FadeColor);						//フェードの色(透明度）
	m_Spritefade->SetMulColor(m_FadeColor);						//フェードの色(透明度）
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<GameDelete>(0,"GameDelete");
		NewGO<GameSence>(0,"GameSence");
		fadein = true;
	}
}
