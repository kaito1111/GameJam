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
	//PlayerBulletという名前のゲームオブジェクトに対してクエリ（問い合わせ）を行う。
	QueryGOs<Buhin>("Buhin1", [&](Buhin* buhin1) {
		if (buhin1->m_position.y >= 300.0f) {

			m_hozon = buhin1->m_position;	
			Buhin1 = true;
			//falseを返したらクエリは終了。
		}
		return true;
	});

	//PlayerBulletという名前のゲームオブジェクトに対してクエリ（問い合わせ）を行う。
	QueryGOs<Buhin>("Buhin2", [&](Buhin* buhin2) {
		if (buhin2->m_position.y >= 300.0f) {

			m_hozon = buhin2->m_position;	
			Buhin2 = true;
			//falseを返したらクエリは終了。
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

	//クラフト画面の位置
	m_position.x = 450.0f;
	m_position.y = 250.0f;

	//スケール
	scale.x = 1.5f;
	scale.y = 1.5f;
	scale.z = 1.0f;

	m_hituyoubuhin1 = NewGO<prefab::CSpriteRender>(0);
	m_hituyoubuhin1->Init(L"sprite/buhin1.dds", 400.0f, 250.0f);
	CVector3 buhin1pos = CVector3::Zero;

	buhin1pos.x = 300.0f;
	buhin1pos.y = 0.0f;

	m_hituyoubuhin1->SetPosition(buhin1pos);
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
			m_BuhinModelRender1->Init(L"modelData/buhin1.cmo");
			m_hozon.x = -300.0f;
			m_hozon.y = 200.0f;
			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 15.0f;
			scale.y = 15.0f;
			scale.z = 15.0f;

			effect->SetScale(scale);
			effect->SetPosition(m_hozon);
			m_BuhinModelRender1->SetPosition(m_hozon);

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
			m_hozon.x = -400.0f;
			m_hozon.y = 200.0f;
			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 15.0f;
			scale.y = 15.0f;
			scale.z = 15.0f;

			effect->SetScale(scale);
			effect->SetPosition(m_hozon);
			m_BuhinModelRender2->SetPosition(m_hozon);

			BuhinCount2 = 1;
			Buhin2 = false;
		}
	}

}