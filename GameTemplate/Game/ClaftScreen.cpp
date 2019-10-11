#include "stdafx.h"
#include "ClaftScreen.h"
#include "Arm.h"
#include "Buhin.h"
#include "result.h"
#include "BeltCon.h"

ClaftScreen::ClaftScreen()
{
}

ClaftScreen::~ClaftScreen()
{
	DeleteGO(m_spriteRender);
	DeleteGO(m_BuhinModelRender1);
	DeleteGO(m_BuhinModelRender2);
	DeleteGO(m_bgmSoundSource);
}

//クエリ関係
void ClaftScreen::Query()
{
	QueryGOs<Buhin>("Buhin1", [&](Buhin* buhin1) {
		if (buhin1->m_position.y >= 600.0f) {

			Buhin1 = true;
			//falseを返したらクエリは終了。
		}
		if (GameOver)
		{
			buhin1->m_position.y -= 30.0f;
		}
		return true;
	});

	QueryGOs<Buhin>("Buhin2", [&](Buhin* buhin2) {
		if (buhin2->m_position.y >= 600.0f) 
		{
			Buhin2 = true;
			//falseを返したらクエリは終了。
		}
		if (GameOver)
		{
			buhin2->m_position.y -= 30.0f;
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
	QueryGOs<BeltCon>("BC", [&](BeltCon* belcon) {
		if (GameOver)
		{
			belcon->m_position.y -= 30.0f;
		}
		return true;
	});
}

//そろっていない部品の表示
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

//クリア後の回転
void ClaftScreen::rotation()
{	
	rot1 = 0.2f;	//毎フレーム回転する量

	//タイヤ1つ目回転
	qrot.SetRotationDeg(CVector3::AxisY, rot1);
	qRot.Multiply(qrot);
	////モデルに回転を反映
	m_BuhinModelRender1->SetRotation(qRot);
	////モデルに回転を反映
	m_BuhinModelRender2->SetRotation(qRot);
}

//クラフトするときの動作
void ClaftScreen::claft()
{
	if (BuhinCount1 == 0)
	{
		if (Buhin1 == true)
		{
			//音を再生
			sound();
			Buhin1 = true;

			//ゲームシーンのGameOverのフラグがたったら動かなくなる

			m_taiya = NewGO < prefab::CSpriteRender> (0, "taiya");
			m_taiya->Init(L"sprite/taiya2.dds", 250.0f, 250.0f);
			m_taiyapos.x = 400.0f;
			m_taiyapos.y = 150.0f;

			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 50.0f;
			scale.y = 50.0f;
			scale.z = 50.0f;

			effect->SetScale(scale);
			effect->SetPosition(effectpos);
			m_taiya->SetPosition(m_taiyapos);
			BuhinCount1 = 1;
			Buhin1 = false;
		}
	}

	if (BuhinCount2 == 0)
	{
		if (Buhin2 == true)
		{
			//音を再生
			sound();
			m_gaisou = NewGO < prefab::CSpriteRender>(0, "taiya");
			m_gaisou->Init(L"sprite/gaisou.dds", 250.0f, 250.0f);
			m_gaisoupos.x = 387.0f;
			m_gaisoupos.y = 230.0f;
			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 50.0f;
			scale.y = 50.0f;
			scale.z = 50.0f;

			effect->SetScale(scale);
			effect->SetPosition(effectpos);
			m_gaisou->SetPosition(m_gaisoupos);
			BuhinCount2 = 1;
			Buhin2 = false;
		}
	}
}

void ClaftScreen::sound()
{
	prefab::CSoundSource* ss;
	ss = NewGO<prefab::CSoundSource>(0);
	ss->Init(L"sound/buhin_atari_kouho2.wav");
	ss->Play(false);
}
bool ClaftScreen::Start()
{
	GD = FindGO<GameDelete>("GameDelete");
    Buhin* buhin1 = nullptr;	//部品1
	Buhin* buhin2 = nullptr;	//部品2
	Buhin* buhin3 = nullptr;	//部品3

	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/ClaftScreen.dds",400.0f,250.0f);

	//エフェクトの位置
	effectpos.x = -450.0f;
	effectpos.y = 250.0f;

	//クラフト画面の位置
	m_position.x = 450.0f;
	m_position.y = 250.0f;

	//スケール
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
	//クエリ関係
	Query();
	//クラフトするときの動作
	claft();
	//そろっていない部品の表示
	hituyoubuhin();

	if (scale.x <= 5.8f)
	{
		if (BuhinCount1 == 1 && BuhinCount2 == 1)
		{
			if (GameOver == false)
			{
				//エフェクトを作成。
				prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
				//エフェクトを再生。
				effect->Play(L"effect/create.efk");
				CVector3 scale = CVector3::One;
				scale.x = 50.0f;
				scale.y = 50.0f;
				scale.z = 50.0f;

				DeleteGO(m_taiya);
				DeleteGO(m_gaisou);
				m_BuhinModelRender1 = NewGO<prefab::CSkinModelRender>(0, "taiyakansei");
				m_BuhinModelRender1->Init(L"modelData/taiyakansei.cmo");
				m_BuhinModelRender2 = NewGO<prefab::CSkinModelRender>(0, "gaisoukansei");
				m_BuhinModelRender2->Init(L"modelData/body.cmo");
				m_taiyapos.x = -300.0f;
				m_taiyapos.y = 250.0f;
				m_gaisoupos.x = -300.0f;
				m_gaisoupos.y = 250.0f;

				effect->SetScale(scale);
				effect->SetPosition(effectpos);
				m_BuhinModelRender1->SetPosition(m_taiyapos);
				m_BuhinModelRender2->SetPosition(m_gaisoupos);
				GameOver = true;
			}
			if (GameOver == true)
			{
				scale.x += 0.05f;
				scale.y += 0.045f;
				buhinscale.x += 0.027f;
				buhinscale.y += 0.027f;
				buhinscale.z += 0.027f;
				buhinscale2.x += 0.005f;
				buhinscale2.y += 0.005f;
				buhinscale2.z += 0.005f;
				m_taiyapos.x += 3.4f;
				m_taiyapos.y -= 2.5f;
				m_taiyapos.z -= 0.3f;
				m_gaisoupos.x += 3.4f;
				m_gaisoupos.y -= 2.5f;
				m_gaisoupos.z -= 0.3f;

				m_BuhinModelRender1->SetScale(buhinscale);
				m_BuhinModelRender1->SetPosition(m_taiyapos);
				m_BuhinModelRender2->SetScale(buhinscale2);
				m_BuhinModelRender2->SetPosition(m_gaisoupos);
			}
			count++;
		}
	}

	if (senni == false)
	{
		if (count >= 60)
		{
			NewGO<result>(2);
			senni = true;
		}
	}
	if (senni == true)
	{
		//クリア後の回転
		rotation();
	}
	   
	if (GD->DeleteClaftScreen == true)
	{
		DeleteGO(this);
	}
	m_spriteRender->SetScale(scale);
}