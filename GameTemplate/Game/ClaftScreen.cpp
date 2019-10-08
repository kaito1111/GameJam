#include "stdafx.h"
#include "ClaftScreen.h"

ClaftScreen::ClaftScreen()
{

}

ClaftScreen::~ClaftScreen()
{

}

bool ClaftScreen::Start()
{
	CVector3 scale = CVector3::Zero;
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ClaftScreen.cmo");

	//クラフト画面の位置
	m_position.x = -250.0f;
	m_position.y = 100.0f;

	//スケール
	scale.x = 2.5f;
	scale.y = 2.5f;
	scale.z = 2.5f;

	m_skinModelRender->SetScale(scale);
	m_skinModelRender->SetPosition(m_position);
	return true;
}

void ClaftScreen::Update()
{

}