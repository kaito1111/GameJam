#include "stdafx.h"
#include "ClaftScreen.h"
#include "Arm.h"
#include "Buhin.h"
#include "result.h"

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

			//m_hozon = buhin1->m_position;	
			Buhin1 = true;
			//false��Ԃ�����N�G���͏I���B
		}
		return true;
		});

	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G���i�₢���킹�j���s���B
	QueryGOs<Buhin>("Buhin2", [&](Buhin* buhin2) {
		if (buhin2->m_position.y >= 300.0f) {

			//m_hozon = buhin2->m_position;	
			Buhin2 = true;
			//false��Ԃ�����N�G���͏I���B
		}
		return true;
		});

	QueryGOs<Arm>("Arm", [&](Arm* arm) {
		if (GameOver)
		{
			arm->m_ArmPosition.x += 30.0f;
		}
		return true;
	});
}

void ClaftScreen::hituyoubuhin()
{
	if (hituyoubuhin1 == false)
	{
		if (BuhinCount1 == 1)
		{
			buhin1pos.x += 8.0f;

		}
		if (buhin1pos.x >= 900.0f)
		{
			DeleteGO(m_hituyoubuhin1);
			hituyoubuhin1 = true;
		}
	}

	if (hituyoubuhin2 == false)
	{
		if (BuhinCount2 == 1)
		{
			buhin2pos.x += 8.0f;
		}	
		if (hituyoubuhin1 == true)
		{
			if (buhin2pos.y <= 25.0f)
			{
				buhin2pos.y += 2;
			}
		}
		if (buhin2pos.x >= 900.0f)
		{
			DeleteGO(m_hituyoubuhin2);
			hituyoubuhin2 = true;
		}
	}
	m_hituyoubuhin1->SetPosition(buhin1pos);
	m_hituyoubuhin2->SetPosition(buhin2pos);
}
bool ClaftScreen::Start()
{
	//buhin1 = FindGO<Buhin>("Buhin1");
	//buhin2 = FindGO<Buhin>("Buhin2");
	//buhin3 = FindGO<Buhin>("Gomi");
    Buhin* buhin1 = nullptr;	//���i1
	Buhin* buhin2 = nullptr;	//���i2
	Buhin* buhin3 = nullptr;	//���i3


	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/ClaftScreen.dds",400.0f,250.0f);

	//�N���t�g��ʂ̈ʒu
	m_position.x = 450.0f;
	m_position.y = 250.0f;

	//�X�P�[��
	scale.x = 1.5f;
	scale.y = 1.5f;
	scale.z = 1.0f;

	m_hituyoubuhin1 = NewGO<prefab::CSpriteRender>(0);
	m_hituyoubuhin1->Init(L"sprite/hituyoubuhin1.dds", 500.0f, 80.0f);

	buhin1pos.x = 400.0f;
	buhin1pos.y = 25.0f;

	m_hituyoubuhin2 = NewGO<prefab::CSpriteRender>(0);
	m_hituyoubuhin2->Init(L"sprite/hituyoubuhin2.dds", 500.0f, 80.0f);


	buhin2pos.x = 400.0f;
	buhin2pos.y = -50.0f;


	m_spriteRender->SetScale(scale);
	m_spriteRender->SetPosition(m_position);
	return true;
}

void ClaftScreen::Update()
{
	Query();

	if (BuhinCount1 == 0)
	{
		if (Buhin1 == true)
		{
			Buhin1 = true;
			m_BuhinModelRender1 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
			m_BuhinModelRender1->Init(L"modelData/wheel.cmo");
			m_Buhin1pos.x = -300.0f;
			m_Buhin1pos.y = 200.0f;
			//�G�t�F�N�g���쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//�G�t�F�N�g���Đ��B
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 15.0f;
			scale.y = 15.0f;
			scale.z = 15.0f;

			effect->SetScale(scale);
			effect->SetPosition(m_Buhin1pos);
			m_BuhinModelRender1->SetPosition(m_Buhin1pos);

			BuhinCount1 = 1;
			Buhin1 = false;
		}
	}

	if (BuhinCount2 == 0)
	{
		if (Buhin2 == true)
		{
			m_BuhinModelRender2 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin2");
			m_BuhinModelRender2->Init(L"modelData/buhin2.cmo");
			m_Buhin2pos.x = -400.0f;
			m_Buhin2pos.y = 200.0f;
			//�G�t�F�N�g���쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//�G�t�F�N�g���Đ��B
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 15.0f;
			scale.y = 15.0f;
			scale.z = 15.0f;

			effect->SetScale(scale);
			effect->SetPosition(m_Buhin2pos);
			m_BuhinModelRender2->SetPosition(m_Buhin2pos);

			BuhinCount2 = 1;
			Buhin2 = false;
		}
	}

	hituyoubuhin();

	if (scale.x <= 5.8f)
	{
		if (BuhinCount1 == 1 && BuhinCount2 == 1)
		{
			GameOver = true;

			scale.x += 0.05f;
			scale.y += 0.045f;
			buhinscale.x += 0.05f;
			buhinscale.y += 0.05f;
			buhinscale.z += 0.05f;
			m_Buhin1pos.x += 4.0f;
			m_Buhin1pos.y -= 3.0f;
			m_Buhin2pos.x += 4.0f;
			m_Buhin2pos.y -= 3.0f;
			m_BuhinModelRender1->SetScale(buhinscale);	
			m_BuhinModelRender1->SetPosition(m_Buhin1pos);
			m_BuhinModelRender2->SetScale(buhinscale);
			m_BuhinModelRender2->SetPosition(m_Buhin2pos);
			count++;
		}
	}

	if (count >= 60)
	{

		NewGO<result>(0);
	}
	m_spriteRender->SetScale(scale);
}