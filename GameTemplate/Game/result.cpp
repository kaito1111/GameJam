#include "stdafx.h"
#include "result.h"
#include "score.h"
#include "title.h"
#include "GameSence.h"

result::result()
{
}

result::~result()
{
	DeleteGO(m_SpriteTitle);
	DeleteGO(m_SpriteReStart);
	DeleteGO(m_SpriteSelect);
}

bool result::Start()
{
	NewGO<score>(0);
	return true;
}

void result::Update()
{
	SpriteGO = GameTime().GetFrameDeltaTime();
	if (SpriteGO >= 1.0f)
	{
		if (New) {
			m_SpriteTitle = NewGO<prefab::CSpriteRender>(1);
			m_SpriteTitle->Init(L"sprite/result_restart.dds", 400.0f, 300.0f);
			m_SpriteTitle->SetPosition(m_TitlePosition);
			m_SpriteReStart = NewGO < prefab::CSpriteRender>(1);
			m_SpriteReStart->Init(L"sprite/result_title.dds", 400.0f, 300.0f);
			m_SpriteReStart->SetPosition(m_ReStartPosition);
			m_SpriteSelect = NewGO<prefab::CSpriteRender>(0);
			m_SpriteSelect->Init(L"sprite/result_select.dds", 405.0f, 305.0);
			New = true;
		}
		if (Pad(0).IsPress(enButtonRight))
		{
			m_SelectPosition.x += 600.0f;
		}
		if (Pad(0).IsPress(enButtonLeft))
		{
			m_SelectPosition.x -= 600.0f;
		}
		if (m_SelectPosition.x >= 300.0f)
		{
			m_SelectPosition.x = 300.0f;
		}
		if (m_SelectPosition.x <= -300.0f)
		{
			m_SelectPosition.x = -300.0f;
		}
		m_SpriteSelect->SetPosition(m_SelectPosition);
		if (m_SelectPosition.x == 200.0f && Pad(0).IsPress(enButtonB))
		{
			NewGO<GameSence>(0, "GameSence");
			DeleteGO(this);
		}
		if (m_SelectPosition.x == -200.0f && Pad(0).IsPress(enButtonB))
		{
			NewGO<Title>(0);
			DeleteGO(this);
		}
	}
}
