#include "stdafx.h"
#include "result.h"
#include "score.h"

result::result()
{
}

result::~result()
{
}

bool result::Start()
{
	m_SpriteTitle = NewGO<prefab::CSpriteRender>(0);
	m_SpriteTitle->Init(L"sprite/result_restart.dds", 400.0f, 300.0f);
	m_SpriteTitle->SetPosition(m_TitlePosition);
	m_SpriteReStart = NewGO < prefab::CSpriteRender>(0);
	m_SpriteReStart->Init(L"sprite/result_title.dds", 400.0f, 300.0f);
	m_SpriteReStart->SetPosition(m_ReStartPosition);
	m_SpriteSelect = NewGO<prefab::CSpriteRender>(0);
	NewGO< score>(0);
	return true;
}

void result::Update()
{

}
