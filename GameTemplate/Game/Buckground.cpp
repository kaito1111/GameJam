#include "stdafx.h"
#include "Buckground.h"

Buckground::Buckground()
{
}

Buckground::~Buckground()
{
}

bool Buckground::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(
		L"sprite/haikei.dds",
		1280.0f,
		720.0f,
		true
	);
	m_spriteRender->SetPosition(m_SpritePos);
	m_spriteRender->SetMulColor(m_SpriteColor);
	return true;
}
