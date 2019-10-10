#include "stdafx.h"
#include "Buckground.h"

Buckground::Buckground()
{
}

Buckground::~Buckground()
{
	DeleteGO(m_spriteRender);
}

bool Buckground::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(
		L"sprite/haikei.dds",
		2560.0f,
		1440.0f,
		true
	);
	m_spriteRender->SetPosition(m_SpritePos);
	m_GameDelete = FindGO<GameDelete>("GameDelete");
		return true;
}

void Buckground::Update()
{
	CQuaternion m_Rot = CQuaternion::Identity;
	m_Rot.SetRotationDeg(CVector3::AxisX, 180.0f);
	CQuaternion m_Rot2 = CQuaternion::Identity;
	m_Rot2.SetRotationDeg(CVector3::AxisZ, 180.0f);
	m_Rot.Multiply(m_Rot2);
	m_spriteRender->SetRotation(m_Rot);
	if (m_GameDelete)
	{
		DeleteGO(this);
	}
}
