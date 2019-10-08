#include "stdafx.h"
#include "BeltCon.h"

BeltCon::BeltCon()
{
}

BeltCon::~BeltCon()
{
}

bool BeltCon::Start()
{
	//データの読み込み
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.cmo");

	//大きさの調整
	scale.x = 18.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//位置の調整
	m_position.y = -350.0f;
	m_skinModelRender->SetPosition(m_position);

	return true;
}

void BeltCon::Update()
{
	/*float m_timer = GameTime().GetFrameDeltaTime();
	if (m_timer = 5) {
		//NewGO<Buhin>(0);
	}*/
}