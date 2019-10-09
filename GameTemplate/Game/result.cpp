#include "stdafx.h"
#include "result.h"
#include "score.h"
#include "title.h"

result::result()
{
}

result::~result()
{
}

bool result::Start()
{
	m_SpriteTitle = NewGO<prefab::CSpriteRender>(1);
	m_SpriteTitle->Init(L"sprite/result_restart.dds", 400.0f, 300.0f);
	m_SpriteTitle->SetPosition(m_TitlePosition);
	m_SpriteReStart = NewGO < prefab::CSpriteRender>(1);
	m_SpriteReStart->Init(L"sprite/result_title.dds", 400.0f, 300.0f);
	m_SpriteReStart->SetPosition(m_ReStartPosition);
	m_SpriteSelect = NewGO<prefab::CSpriteRender>(0);
	m_SpriteSelect->Init(L"sprite/result_select.dds", 450.0f, 350.0);
	m_SpriteSelect->SetPosition(m_SelectPosition);

	NewGO<score>(0);
	return true;
}

void result::Update()
{
	if (Pad(0).IsPress(enButtonRight))
	{
		m_SelectPosition.x += 400.0f;
	}
	if (Pad(0).IsPress(enButtonLeft))
	{
		m_SelectPosition.x -= 400.0f;
	}
	if (m_SelectPosition.x >= 200.0f)
	{
		m_SelectPosition.x = 200.0f;
	}
	if (m_SelectPosition.x <= -200.0f)
	{
		m_SelectPosition.x = -200.0f;
	}
	m_SpriteSelect->SetPosition(m_SelectPosition);
	if (m_SelectPosition.x == 200.0f&&Pad(0).IsPress(enButtonB))
	{
		NewGO<GameSence>(0, "GameSence");
	}
	if (m_SelectPosition.x == -200.0f && Pad(0).IsPress(enButtonB))
	{
		NewGO<Title>(0);;
	}
}
