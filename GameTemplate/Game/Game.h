#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"


class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
};

