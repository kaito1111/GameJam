#include "stdafx.h"
#include "Buhin.h"
#include "Arm.h"
#include "ClaftScreen.h"
#include "BeltCon.h"
#include "GameDelete.h"
#include "GameSence.h"

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
	GD = FindGO<GameDelete>("GameDelete");
	arm = FindGO<Arm>("Arm");
	CS = FindGO<ClaftScreen>("cs");
	//FindしてBeltConの値を参照できるように
	belt = FindGO<BeltCon>("BC");
	m_Sence = FindGO<GameSence>("GameSence");
	//ベルトコンベアからrandの値を参照する
	rand = belt->rand;
	hantei();

	//大きさの初期化
	Scale.x = 1;
	Scale.y = 1;
	Scale.z = 1;

	//スキン
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	//"部品"を追加したらこことBeltCon.cppに追加してください//
	//ベルトコンベアクラスでbuhin1が作られたら
	//車輪なら
	if (IamWheel == 1) {
		//大きさ
		Scale.z = 4;
		Scale.y = 4;
		m_skinModelRender->SetScale(Scale);

		//座標
		m_position.x = -800;
		m_position.y = -260;

		//角度
		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
		m_skinModelRender->SetRotation(qRot);

		//buhin1のモデルデータのロード
		m_skinModelRender->Init(L"modelData/wheel.cmo");
	}
	//フレームなら
	else if (Iamframe == 1) {
		//座標
		m_position.x = -800;
		m_position.y = -280;
		
		//大きさ
		Scale.x = 1;
		Scale.y = 1;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//buhin2のモデルデータのロード
		m_skinModelRender->Init(L"modelData/body.cmo");
	}
	//ゴミなら
	else if(IamGomi == 1){

		//座標
		m_position.x = -800;
		m_position.y = -330;

		//大きさ
		Scale.x = 2;
		Scale.y = 2;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//ゴミのモデルデータのロード
		m_skinModelRender->Init(L"modelData/garakuta1.cmo");
	}
	//扉なら
	else if (IamGomi2 == 1) {
		//座標
		m_position.x = -800;
		m_position.y = -350;

		//大きさ
		Scale.x = 1;
		Scale.y = 1;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//ゴミのモデルデータのロード
		m_skinModelRender->Init(L"modelData/garakuta2.cmo");
	}
	else if (IamTake == 1) {
		m_position.x = -800;
		m_position.y = -210;

		//大きさ
		Scale.x = 5;
		Scale.y = 5;
		Scale.z = 5;
		m_skinModelRender->SetScale(Scale);

		//ゴミのモデルデータのロード
		m_skinModelRender->Init(L"modelData/garakuta3.cmo");
	}

	//流れる速さ
	m_moveSpeed.x = 2.5f;

	//部品が出てくる初期位置
	return true;
}

void Buhin::Update()
{
	//クラフトスクリーンのGameOverフラグがTrueならば
	if (CS->GameOver == true) {
		DeleteGO(this);
	}
	//クエリでアームにキャッチされているのかの判定を行う
	QueryGOs<Arm>("Arm", [&](Arm* arm)->bool {
		CVector3 diff;
		diff.y = arm->m_ArmPosition.y - m_position.y;
		/*dif.yだけの方を少し下げることで当たりX軸の当たり判定はそのままで
		Y軸の当たり判定を無理やり広める*/
		//Y軸の当たり判定がおかしいときはここの値を調整してください
		if (IamGomi2 == 1) {
			//どこでもドアのY軸の当たり判定調整
			diff.y -= 180;
		}
		else if(Iamframe == 1){
			//フレームのY軸の当たり判定調整
			diff.y -= 120;
		}
		else {
			//レンジとタイヤの当たり判定調整
			diff.y -= 150;
		}
		diff.x = arm->m_ArmPosition.x - m_position.x;
		//当たり判定を大きくするときはここを調整
		if (diff.Length() < 100) {
			//アームの腕がまがったらキャッチフラグを立てる
			if (arm->Rotrate >= 15.0f) {
				//とりあえずキャッチ
				IsCatch = true;
			}
			if (IamWheel == 1 && CS->BuhinCount1 == 0 ||
				Iamframe == 1 && CS->BuhinCount2 == 0)
			{
				//これが必要なパーツならとる
				arm->Catch = true;
			}
			return false;
		}
		return true;
	});

	//何かものをつかんでいるならば
	//キャッチしている位置がおかしいならここを変更してください
	if (IsCatch == true) {
		if (IamGomi2 == 1) {
			//つかまれたどこでもドアの位置調整
			m_position.y = arm->m_ArmPosition.y - 240;
			m_position.x = arm->m_ArmPosition.x;
		}
		else if (Iamframe == 1) {
			//つかまれたフレームの位置調整
			m_position.y = arm->m_ArmPosition.y - 150;
			m_position.x = arm->m_ArmPosition.x;
		}
		else if(IamWheel == 1){
			//つかまれたタイヤの位置調整
			m_position.y = arm->m_ArmPosition.y - 180;
			m_position.x = arm->m_ArmPosition.x;
		}
		else {
			//つかまれたレンジの位置調整
			m_position.y = arm->m_ArmPosition.y - 220;
			m_position.x = arm->m_ArmPosition.x;
		}
	}
	//いらないパーツなら
	if (arm->Catch == false) {
		if (arm->m_ArmPosition.y >= 300)
		{
			if (IamWheel == 1) {
				//ベルトコンベアに戻す
				m_position.y = -280.0f;
			}
			else if (Iamframe == 1) {
				m_position.y = -260.0f;
			}
			else if (IamGomi == 1) {
				m_position.y = -330.0f;
			}
			else {
				m_position.y = -350.0f;
			}
			//何ももってない
			IsCatch = false;
		}
	}

	//Y軸が画面外になるとそのオブジェクトを消す
	//★600以下にしないでください★
	if (m_position.y >= 650) {
		DeleteGO(this);
		//何ももってない
		arm->Catch = false;
	}

	//クレーンが動いてるあいだ
	if (arm->Set == false) {
		m_moveSpeed.x = 0.0f;
		//belt->m_timer = 0;
	}
	//クレーンが動いていないなら
	else {
		m_moveSpeed.x = 2.5f;
	}

	//右から左に流す
	m_position.x += m_moveSpeed.x;
	if (!m_Sence->GameOver)
	{
		m_skinModelRender->SetPosition(m_position);
	}
	

	//画面外にでたら削除
	if (m_position.x > 1000) {
		DeleteGO(this);
	}
}

//BeltConで生成された乱数をもとに
//それがどの部品なのかを仕分けする関数
void Buhin::hantei() {
	if (rand == 0) {
		//車輪
		IamWheel = 1;
	}
	else if (rand == 1) {
		//フレーム
		Iamframe = 1;
	}
	else if(rand == 2){
		//ゴミ
		IamGomi2 = 1;
	}
	else if (rand == 3) {
		IamTake = 1;
	}
	else {
		IamGomi = 1;
	}
}
