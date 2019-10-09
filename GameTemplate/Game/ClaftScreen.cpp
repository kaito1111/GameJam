#include "stdafx.h"
#include "ClaftScreen.h"

ClaftScreen::ClaftScreen()
{

}

ClaftScreen::~ClaftScreen()
{

}

void ClaftScreen::Query()
{
	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G���i�₢���킹�j���s���B
	QueryGOs<Buhin>("Buhin1", [&](Buhin* buhin1) {
		if (buhin1->m_position.y >= 300.0f) {

			m_hozon = buhin1->m_position;	
			Buhin1 = true;
			//false��Ԃ�����N�G���͏I���B
		}
		return true;
	});

	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G���i�₢���킹�j���s���B
	QueryGOs<Buhin>("Buhin2", [&](Buhin* buhin2) {
		if (buhin2->m_position.y >= 300.0f) {

			m_hozon = buhin2->m_position;	
			Buhin2 = true;
			//false��Ԃ�����N�G���͏I���B
		}
		return true;
	});
}
bool ClaftScreen::Start()
{
	//buhin1 = FindGO<Buhin>("Buhin1");
	//buhin2 = FindGO<Buhin>("Buhin2");
	//buhin3 = FindGO<Buhin>("Gomi");


	CVector3 scale = CVector3::Zero;
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/ClaftScreen.dds",400.0f,250.0f);

	//�N���t�g��ʂ̈ʒu
	m_position.x = 450.0f;
	m_position.y = 250.0f;

	//�X�P�[��
	scale.x = 1.5f;
	scale.y = 1.5f;
	scale.z = 1.0f;

	m_spriteRender->SetScale(scale);
	m_spriteRender->SetPosition(m_position);
	return true;
}

void ClaftScreen::Update()
{
	Query();

	if (Buhin1 == true)
	{
		Buhin1 = true;
		m_BuhinModelRender1 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
		m_BuhinModelRender1->Init(L"modelData/buhin1.cmo");
		m_hozon.x = 100.0f;
		m_hozon.y = 100.0f;

		m_BuhinModelRender1->SetPosition(m_hozon);

		Buhin1 = false;
	}

	if (Buhin2 == true)
	{
		m_BuhinModelRender2 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin2");
		m_BuhinModelRender2->Init(L"modelData/buhin2.cmo");
		m_hozon.x = 100.0f;
		m_hozon.y = 100.0f;

		m_BuhinModelRender2->SetPosition(m_hozon);

		Buhin2 = false;
	}

}