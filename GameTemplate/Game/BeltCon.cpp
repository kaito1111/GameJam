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
	//�f�[�^�̓ǂݍ���
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.cmo");

	//�傫���̒���
	scale.x = 18.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//�ʒu�̒���
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