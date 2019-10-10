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
	swprintf_s(ScoreMoji, L"%3d�_", Score);				//�X�R�A�̃Z�b�g
	m_scoreFont = NewGO<prefab::CFontRender>(0);
	m_scoreFont->SetText(ScoreMoji);					//��������Z�b�g
	m_scoreFont->SetColor(m_FontColor);				//�t�H���g�̐F���Z�b�g
	m_scoreFont->SetPosition(m_FontPosition);				//�t�H���g�̈ʒu��
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
