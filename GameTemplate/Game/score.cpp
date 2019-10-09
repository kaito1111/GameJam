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

	Score = m_Sence->time;
	swprintf_s(ScoreMoji, L"%3d“_", Score);
	m_scoreFont = NewGO<prefab::CFontRender>(0);
	m_scoreFont->SetText(ScoreMoji);
	m_scoreFont->SetColor(m_FontColor);

	return true;
}

void score::Update()
{
	
}
