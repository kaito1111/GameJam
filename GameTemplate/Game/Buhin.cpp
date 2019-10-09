#include "stdafx.h"
#include "Buhin.h"
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
	//クラス変数
	BeltCon* belt;
	//Find
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
		m_skinModelRender->Init(L"modelData/buhin1.cmo");
	}
	else if (belt->rand == 1) {
		//buhin2のモデルデータのロード
		m_skinModelRender->Init(L"modelData/buhin2.cmo");
	}
	else {
		//ゴミのモデルデータのロード
		m_skinModelRender->Init(L"modelData/Gomi.cmo");
	}

	m_skinModelRender->SetScale(Scale);

	//流れる速さ
	m_moveSpeed.x = 2.5f;

	//部品が出てくる初期位置
	m_position.x = -700;
	m_position.y = -330;
	return true;
}

void Buhin::Update()
{
	//右から左に流す
	m_position.x += m_moveSpeed.x;
	m_skinModelRender->SetPosition(m_position);

	//画面外にでたら削除
	if (m_position.x > 750) {
		DeleteGO(this);
	}
}
