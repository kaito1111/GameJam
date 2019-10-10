#include "stdafx.h"
#include "GameCamera.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

	m_Ground = FindGO<Buckground>("Buckground");
}

bool GameCamera::Start()
{
	//ƒJƒƒ‰‚ğİ’èB

	MainCamera().SetTarget({ 0.0f,0.0f,0.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().SetPosition({ 0.0f, 0.0f, 700.0f });
	MainCamera().Update();
	return true;
}

void GameCamera::Update()
{
	CVector3 m_Position = CVector3::Zero;
	QueryGOs<Buckground>("Buckground", [&](Buckground* m_Ground)->bool
		{
			m_Position = m_Ground->m_SpritePos;
			return true;
		});

	MainCamera().SetTarget(m_Position);
}
