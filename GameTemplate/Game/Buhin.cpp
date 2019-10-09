#include "stdafx.h"
#include "Buhin.h"
#include "Arm.h"
#include "BeltCon.h"

Buhin::Buhin()
{
}

Buhin::~Buhin()
{
	DeleteGO(m_skinModelRender);
}

/*クラスを使いまわしできるようにするため
ベルトコンベアからrandの値を参照して
そのrandに対応したモデルデータを読み込ませる*/

bool Buhin::Start()
{
	arm = FindGO<Arm>("Arm");
	//FindしてBeltConの値を参照できるように
	belt = FindGO<BeltCon>("BC");
	//ベルトコンベアからrandの値を参照する
	int rand = belt->rand;

	//大きさの調整
	CVector3 Scale;
	Scale.x = 5;
	Scale.y = 3;
	Scale.z = 3;

	//スキン
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	//"部品"を追加したらこことBeltCon.cppに追加してください//
	//ベルトコンベアクラスでbuhin1が作られたら
	if (belt->rand == 0) {
		//buhin1のモデルデータのロード
		m_skinModelRender->Init(L"modelData/wheel.cmo");
		//大きさ
		Scale.x = 3;
		Scale.y = 5;
		Scale.z = 5;
		m_skinModelRender->SetScale(Scale);

		//座標
		m_position.x = -700;
		m_position.y = -350;
		m_position.z = 0;

		//角度
		//qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
		m_skinModelRender->SetRotation(qRot);
	}
	else if (belt->rand == 1) {
		m_position.x = -700;
		m_position.y = -330;
		//buhin2のモデルデータのロード
		m_skinModelRender->Init(L"modelData/buhin2.cmo");
	}
	else {
		//ゴミのモデルデータのロード
		m_position.x = -800;
		m_position.y = -330;
		m_skinModelRender->Init(L"modelData/Gomi.cmo");
	}

	m_skinModelRender->SetScale(Scale);

	//流れる速さ
	m_moveSpeed.x = 2.5f;

	//部品が出てくる初期位置
	return true;
}

void Buhin::Update()
{
	//クエリでアームにキャッチされているのかの判定を行う

	QueryGOs<Arm>("Arm", [&](Arm* arm)->bool {
		CVector3 diff = arm->m_ArmPosition - m_position;
		//当たり判定
		if (diff.Length() < 80) {
			IsCatch = true;
			if (!IamGomi)
			{
				arm->Catch = true;
			}
			return false;
		}
		return true;
		});

	if (IsCatch == true) {
		//部品の高さをアームの高さに揃える
		m_position.y = arm->m_ArmPosition.y;
	}

	//画面外にでたら削除
	if (m_position.x > 750) {
		DeleteGO(this);
	}
	//クレーンが動いてるあいだ
	if (arm->Set == false) {
		m_moveSpeed.x = 0.0f;
		belt->m_timer = 0;
	}
	else {
		m_moveSpeed.x = 2.5f;
	}
	//Y軸が画面外になるとそのオブジェクトを消す
	//★600以下にしないでください★
	if (m_position.y >= 650) {
		DeleteGO(this);
		arm->Catch = false;
	}
	else {
		//arm->Catch = false;
	}
	if (IamGomi && arm->m_ArmPosition.y >= 200)
	{
		m_position.y = -330.0f;
		IsCatch = false;
	}
	//右から左に流す
	m_position.x += m_moveSpeed.x;
	m_skinModelRender->SetPosition(m_position);
}
