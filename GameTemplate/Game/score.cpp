#include "stdafx.h"
#include "score.h"

score::score()
{
}

score::~score()
{
}

bool score::Start()
{
	m_Sence = FindGO< GameSence>("GameSence");
	Score = m_Sence->time;
	swprintf_s(ScoreMoji, L"%3d“_", Score);
	m_scoreFont = NewGO<prefab::CFontRender>(0);
	m_scoreFont->SetText(ScoreMoji);
	m_scoreFont->SetColor(m_FontColor);
	m_scoreFont->SetPosition(m_FontPosition);
	m_scoreFont->SetScale(1.5f);
	return true;
}

void score::Update()
{
	
}
