#include "stdafx.h"
#include "BeltCon.h"
#include "Buhin.h"
#include "tkEngine/timer/tkGameTime.h"

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

/*ここから部品をランダムに流す処理を書いていく
乱数をXで割ってでた余りの値に応じて
どの部品を流すのか決定していく*/
//★緑が部品1、青が部品2、黒がゴミ
//Generatorみたいな感じ
void BeltCon::Update()
{
	//経過時間
	m_timer += GameTime().GetFrameDeltaTime();
	// m_timer > Xf のXの値をいじるとスポーン時間が変わります
	if (m_timer > 2.0f) {
		//乱数
		rand = Random().GetRandInt();
		// %X をいじるとゴミがでる割合を変えれます
		rand = rand % 8;

		/*それぞれの乱数に対応した"部品"のインスタンスをここで作成します
		"部品"を追加したい場合をこことBuhin.cppに追加してください*/
		if (rand == 0) {
			NewGO<Buhin>(0, "Buhin1");
			//タイマーを初期化
			m_timer = 0;
		}
		else if(rand == 1){
			NewGO<Buhin>(0, "Buhin2");
			m_timer = 0;
		}
		else {
			NewGO<Buhin>(0, "Gomi");
			m_timer = 0;
		}
	}
}
