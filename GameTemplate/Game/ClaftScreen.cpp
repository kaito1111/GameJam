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

}

//クエリ関係
void ClaftScreen::Query()
{
	//PlayerBulletという名前のゲームオブジェクトに対してクエリ（問い合わせ）を行う。
	QueryGOs<Buhin>("Buhin1", [&](Buhin* buhin1) {
		if (buhin1->m_position.y >= 600.0f) {

			buhin1->m_position.y -= 30.0f;
			Buhin1 = true;
			//falseを返したらクエリは終了。
		}
		return true;
		});

	//PlayerBulletという名前のゲームオブジェクトに対してクエリ（問い合わせ）を行う。
	QueryGOs<Buhin>("Buhin2", [&](Buhin* buhin2) {
		if (buhin2->m_position.y >= 600.0f) {

			buhin2->m_position.y -= 30.0f;	
			Buhin2 = true;
			//falseを返したらクエリは終了。
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
	mRot.MakeRotationFromQuaternion(qRot);
	m_forward.x = mRot.m[2][0];
	m_forward.y = mRot.m[2][1];
	m_forward.z = mRot.m[2][2];
	m_forward.Normalize();
	m_right.x = mRot.m[0][0];
	m_right.y = mRot.m[0][1];
	m_right.z = mRot.m[0][2];
	m_right.Normalize();
	m_up.x = mRot.m[1][0];
	m_up.y = mRot.m[1][1];
	m_up.z = mRot.m[1][2];
	m_up.Normalize();

	CVector3 tyuusin = CVector3::Zero;	
	CQuaternion qrot = CQuaternion::Identity;

	//部品から中心に向けてのベクトル
	CVector3 toZero1_1 = m_Buhin1pos - tyuusin;
	toZero1_1.y = 0.0f;
	toZero1_1.Normalize();
	//回転量を計算
	float angle1 = toZero1_1.Dot(m_forward);
	rot1 = acosf(angle1);
	//回転
	qrot.SetRotation(CVector3::AxisY, rot1);
	qRot.Multiply(qrot);
	//モデルに回転を反映
	m_BuhinModelRender1->SetRotation(qRot);

	//部品から中心に向けてのベクトル
	CVector3 toZero1_2 = m_Buhin1_2pos - tyuusin;
	toZero1_2.y = 0.0f;
	toZero1_2.Normalize();
	//回転量を計算
	float angle2 = toZero1_2.Dot(m_forward);
	rot2 = acosf(angle2);
	//回転
	qrot.SetRotation(CVector3::AxisY, rot2);
	qRot.Multiply(qrot);
	//モデルに回転を反映
	m_BuhinModelRender1_2->SetRotation(qRot);

	//部品から中心に向けてのベクトル
	CVector3 toZero1_3 = m_Buhin1_3pos - tyuusin;
	toZero1_3.y = 0.0f;
	toZero1_3.Normalize();
	//回転量を計算
	float angle3 = toZero1_3.Dot(m_forward);
	rot3 = acosf(angle3);
	//回転
	qrot.SetRotation(CVector3::AxisY, rot3);
	qRot.Multiply(qrot);
	//モデルに回転を反映
	m_BuhinModelRender1_3->SetRotation(qRot);

	//部品から中心に向けてのベクトル
	CVector3 toZero1_4 = m_Buhin1_4pos - tyuusin;
	toZero1_4.y = 0.0f;
	toZero1_4.Normalize();
	//回転量を計算
	float angle4 = toZero1_4.Dot(m_forward);
	rot4 = acosf(angle4);
	//回転
	qrot.SetRotation(CVector3::AxisY, rot4);
	qRot.Multiply(qrot);
	//モデルに回転を反映
	m_BuhinModelRender1_4->SetRotation(qRot);
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
			m_BuhinModelRender1 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
			m_BuhinModelRender1->Init(L"modelData/wheel.cmo");
			m_Buhin1pos.x = -350.0f;
			m_Buhin1pos.y = 150.0f;
			m_Buhin1pos.z = 0.0f;
			m_BuhinModelRender1_2 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
			m_BuhinModelRender1_2->Init(L"modelData/wheel.cmo");
			m_Buhin1_2pos.x = -550.0f;
			m_Buhin1_2pos.y = 150.0f;
			m_Buhin1_2pos.z = 0.0f;
			m_BuhinModelRender1_3 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
			m_BuhinModelRender1_3->Init(L"modelData/wheel.cmo");
			m_Buhin1_3pos.x = -350.0f;
			m_Buhin1_3pos.y = 150.0f;
			m_Buhin1_3pos.z = -50.0f;
			m_BuhinModelRender1_4 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin1");
			m_BuhinModelRender1_4->Init(L"modelData/wheel.cmo");
			m_Buhin1_4pos.x = -550.0f;
			m_Buhin1_4pos.y = 150.0f;
			m_Buhin1_4pos.z = -50.0f;

			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
			effect->Play(L"effect/create.efk");
			CVector3 scale = CVector3::One;
			scale.x = 15.0f;
			scale.y = 15.0f;
			scale.z = 15.0f;

			effect->SetScale(scale);
			effect->SetPosition(m_Buhin1pos);
			m_BuhinModelRender1->SetPosition(m_Buhin1pos);
			m_BuhinModelRender1_2->SetPosition(m_Buhin1_2pos);
			m_BuhinModelRender1_3->SetPosition(m_Buhin1_3pos);
			m_BuhinModelRender1_4->SetPosition(m_Buhin1_4pos);
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
			m_BuhinModelRender2 = NewGO < prefab::CSkinModelRender>(0, "ClaftBuhin2");
			m_BuhinModelRender2->Init(L"modelData/body.cmo");
			m_Buhin2pos.x = -400.0f;
			m_Buhin2pos.y = 200.0f;
			//エフェクトを作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			//エフェクトを再生。
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
    Buhin* buhin1 = nullptr;	//部品1
	Buhin* buhin2 = nullptr;	//部品2
	Buhin* buhin3 = nullptr;	//部品3


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
			GameOver = true;

			scale.x += 0.05f;
			scale.y += 0.045f;
			buhinscale.x += 0.02f;
			buhinscale.y += 0.02f;
			buhinscale.z += 0.02f;
			m_Buhin1pos.x += 6.0f;
			m_Buhin1pos.y -= 3.0f;
			m_Buhin1_2pos.x += 4.0f;
			m_Buhin1_2pos.y -= 3.0f;
			m_Buhin1_3pos.x += 6.0f;
			m_Buhin1_3pos.y -= 3.0f;
			m_Buhin1_4pos.x += 4.0f;
			m_Buhin1_4pos.y -= 3.0f;
			m_Buhin2pos.x += 4.0f;
			m_Buhin2pos.y -= 3.0f;
			m_BuhinModelRender1->SetScale(buhinscale);	
			m_BuhinModelRender1->SetPosition(m_Buhin1pos);
			m_BuhinModelRender1_2->SetScale(buhinscale);
			m_BuhinModelRender1_2->SetPosition(m_Buhin1_2pos);
			m_BuhinModelRender1_3->SetScale(buhinscale);
			m_BuhinModelRender1_3->SetPosition(m_Buhin1_3pos);
			m_BuhinModelRender1_4->SetScale(buhinscale);
			m_BuhinModelRender1_4->SetPosition(m_Buhin1_4pos);
			m_BuhinModelRender2->SetScale(buhinscale);
			m_BuhinModelRender2->SetPosition(m_Buhin2pos);
	
			//クリア後の回転
			rotation();

			count++;
		}
	}

	if (senni == false)
	{
		if (count >= 60)
		{
			NewGO<result>(0);
			senni = true;
		}
	}
	m_spriteRender->SetScale(scale);
}