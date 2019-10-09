#include "stdafx.h"
#include "Game.h"
#include "GameCamera.h"
#include "BeltCon.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "test.h"
#include "result.h"

Game::Game()
{
}


Game::~Game()
{
}
bool Game::Start()
{
	NewGO<BeltCon>(0, "BC");
	NewGO<ClaftScreen>(0,"cs");
	NewGO<GameCamera>(0,"gc");
	m_Screen = FindGO< ClaftScreen>("cs");
	return true;
}

void Game::Update()
{
}