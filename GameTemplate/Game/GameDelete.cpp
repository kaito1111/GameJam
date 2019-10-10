#include "stdafx.h"
#include "GameDelete.h"

GameDelete::GameDelete()
{
}

GameDelete::~GameDelete()
{
}

void GameDelete::Update()
{
	if (DeleteArm == true &&
		DeleteGameSence == true &&
		DeleteScore == true &&
		DeleteClaftScreen == true &&
		DeleteBeltCon == true &&
		DeleteBuckGround == true&&
		DeleteBuhin==true)
	{
		DeleteGO(this);
	}
}
