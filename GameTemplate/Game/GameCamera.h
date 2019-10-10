#pragma once
#include "Buckground.h"
class GameCamera:public IGameObject
{
public:
	GameCamera();
	~GameCamera();

	bool Start();
	void Update();

	Buckground* m_Ground = nullptr;
};

