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
}
bool::Title::Start()
{
	//インスタンス
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトルの読み込み
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
	m_BGM = NewGO<prefab::CSoundSource>(0);
	m_BGM->Init(L"sound/bgm_kakutei.wab");
	m_BGM->Play(true);
	m_BGM->SetVolume(1.0f);
	return true;
}

void Title::Update()
{
	//キーボードのKで起動
	//ゲームループはしないので後で修正
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<GameDelete>(0,"GameDelete");
		NewGO<GameSence>(0,"GameSence");

		DeleteGO(this);
	}
}
