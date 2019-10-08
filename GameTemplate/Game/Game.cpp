#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "ClaftScreen.h"
#include "BeltCon.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	NewGO<ClaftScreen>(0,"cs");
	NewGO<GameCamera>(0,"gc");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	
	return true;
}

void Game::Update()
{
}