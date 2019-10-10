#include "stdafx.h"
#include "score.h"
#include "GameSence.h"

score::score()
{
}

score::~score()
{
	DeleteGO(m_scoreFont);
	DeleteGO(m_Sence);
}

bool score::Start()
{
	m_Sence = FindGO< GameSence>("GameSence");
	Score = m_Sence->time;
	swprintf_s(ScoreMoji, L"%3d点", Score);				//スコアのセット
	m_scoreFont = NewGO<prefab::CFontRender>(0);
	m_scoreFont->SetText(ScoreMoji);					//文字列をセット
	m_scoreFont->SetColor(m_FontColor);				//フォントの色をセット
	m_scoreFont->SetPosition(m_FontPosition);				//フォントの位置を
	m_scoreFont->SetScale(1.5f);

	m_Delete = FindGO<GameDelete>("GameDelete");
	return true;
}

void score::Update()
{
	if (m_Delete->DeleteScore)
	{
		DeleteGO(this);
	}
}
