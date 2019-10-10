#pragma once
class GameDelete : public IGameObject
{
public:
	GameDelete();
	~GameDelete();

	void Update();

	bool DeleteBuhin = false;
	bool DeleteArm = false;
	bool DeleteGameSence=false;
	bool DeleteScore = false;
	bool DeleteClaftScreen = false;
	bool DeleteBeltCon = false;
	bool DeleteBuckGround = false;
};