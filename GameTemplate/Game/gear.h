#pragma once
#include "GameDelete.h"
#include "Arm.h"
#include "GameSence.h"

class gear : public IGameObject
{
public:
	gear();
	~gear();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_GearModel = nullptr;
	CVector3 m_Position = CVector3::Zero;
	CQuaternion m_Rot = CQuaternion::Identity;
	CVector3 m_Scale = { 0.5f,0.5f,0.5f };
	float Rotritu = 0.0f;
	GameDelete* m_Delete = nullptr;
	Arm* m_Arm = nullptr;
	GameSence* m_Sense = nullptr;
};