#include "stdafx.h"
#include "Title.h"
#include "Game.h"

Title::Title()
{

}
Title::~Title()
{
	DeleteGO(m_spriteRender);
}
bool::Title::Start()
{
<<<<<<< HEAD
=======
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/GGJ_title.dds", 1280,720,0);
>>>>>>> c3538f83b0fe02d377ab840b9941d9312304d0df
	return true;
}

void Title::Update()
{
	//キーボードのKで起動
	if (Pad(0).IsPress(enButtonB)) {
		NewGO<Game>(0);
		DeleteGO(this);
	}
}
