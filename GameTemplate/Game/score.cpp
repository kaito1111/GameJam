#include "stdafx.h"
#include "score.h"
#include "GameSence.h"

score::score()
{
}

score::~score()
{
	DeleteGO(m_scoreFont);
}

bool score::Start()
{
	m_Sence = FindGO< GameSence>("GameSence");
	Score = Random().GetRandInt();
	swprintf_s(ScoreMoji, L"%03d�_", Score);				//�X�R�A�̃Z�b�g
	m_scoreFont = NewGO<prefab::CFontRender>(0);
	m_scoreFont->SetText(ScoreMoji);						//��������Z�b�g
	m_scoreFont->SetColor(m_FontColor);						//�t�H���g�̐F���Z�b�g
	m_scoreFont->SetPosition(m_FontPosition);				//�t�H���g�̈ʒu��
	m_scoreFont->SetScale(1.5f);

	m_Delete = FindGO<GameDelete>("GameDelete");
	return true;
}

void score::Update()
{
	Setscore += GameTime().GetFrameDeltaTime();
	if (Setscore >= 3.0f)
	{
		Score = m_Sence->time;
	}
	else
	{
		Score = Random().GetRandInt();
	}
	swprintf_s(ScoreMoji, L"%03d�_", Score);				//�X�R�A�̃Z�b�g
	m_scoreFont->SetText(ScoreMoji);						//��������Z�b�g

	if (m_Delete->DeleteScore)
	{
		DeleteGO(this);
	}
}
