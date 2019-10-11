#include "stdafx.h"
#include "BeltCon.h"
#include "Buhin.h"
#include "tkEngine/timer/tkGameTime.h"
#include "GameSence.h"
#include "gear.h"

BeltCon::BeltCon()
{
}

BeltCon::~BeltCon()
{
	DeleteGO(ss);
	DeleteGO(m_skinModelRender);
}

bool BeltCon::Start()
{
	arm = FindGO<Arm>("Arm");
	//データの読み込み
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.cmo");
	m_Sence = FindGO< GameSence>("GameSence");
	//サウンド
	ss = NewGO<prefab::CSoundSource>(0);
	float vol = 0.5f;
	ss->Init(L"sound/Beltcon_Trim.wav");
	ss->SetVolume(vol);
	ss->Play(true);

	//大きさの調整
	scale.x = 18.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//位置の調整
	m_position.y = -350.0f;
	m_skinModelRender->SetPosition(m_position);
	for (int i = 0; i < 5; i++)
	{
		char m_Name[128];
		sprintf_s(m_Name, "gear%d", i);
		NewGO<gear>(0, m_Name);
		m_gear[i] = FindGO<gear>(m_Name);
	}
	for (int i = 0; i < 5; i++)
	{

		m_gear[i]->m_Position = { 600.0f - (i * 300.0f),-450.0f,0.0f };
	}
	return true;
}

/*ここから部品をランダムに流す処理を書いていく
乱数をXで割ってでた余りの値に応じて
どの部品を流すのか決定していく*/
//★緑が部品1、青が部品2、黒がゴミ
//Generatorみたいな感じ
void BeltCon::Update()
{
	//クラフト画面が拡大されたらBeltConが下に降りてって消える
	if (m_position.y <= -500) {
		DeleteGO(this);
	}
	//アームが動いてる間はサウンドを消す
	if (arm->Set == true) {
		ss->Play(true);
	}
	else {
		ss->Stop();
	}

	//経過時間
	if (!m_Sence->GameOver && arm->Set == true)
	{
		m_timer += GameTime().GetFrameDeltaTime();
	}
	
	// m_timer > Xf のXの値をいじるとスポーン時間が変わります
	if (m_timer > 2.0f) {
		//乱数
		rand = Random().GetRandInt() % waru;
		//randの値をwaru個に分ける
		//rand = rand ;

		/*それぞれの乱数に対応した"部品"のインスタンスをここで作成します
		"部品"を追加したい場合をこことBuhin.cppに追加してください*/
		//少しでも被りを少なくするためにコードがややこしいですがパーツのインスタンスを作っているだけです
		if(count[1] > 2 || rand == 1 && arm->Set == true) {
			rand = 1;
			NewGO<Buhin>(0, "Buhin2");
			m_timer = 0;
			//でたので初期化
			waru = waruh;
			count[0]++;
			count[1] = 0;
		}
		else if (count[0] > 2 || rand == 0 && arm->Set == true) {
			rand = 0;
			NewGO<Buhin>(0, "Buhin1");
			//タイマーを初期化
			m_timer = 0;
			//でたので初期化
			waru = waruh;
			count[1]++;
			count[0] = 0;
		}
		else if(arm->Set == true){
			NewGO<Buhin>(0, "Gomi");
			m_timer = 0;
			//ゴミが連続ででないように調整
			waru--;
		}
	}
}
