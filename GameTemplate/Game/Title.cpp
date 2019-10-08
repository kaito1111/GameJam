#include "stdafx.h"
#include "Title.h"
#include "Game.h"

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
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
	//インスタンス
>>>>>>> bcead7dfc736d1bfcb895de0c8d11c7ddbae7f91
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトルの読み込み
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
>>>>>>> c3538f83b0fe02d377ab840b9941d9312304d0df
	return true;
}

void Title::Update()
{
	//キーボードのKで起動
	//ゲームループはしないので後で修正
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<Game>(0);
		DeleteGO(this);
	}
}
