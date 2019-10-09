#include "stdafx.h"
#include "test.h"

test::test()
{
}

test::~test()
{
	if (InitBox)														//箱
	{
		DeleteGO(m_testBox);
	}
	if (InitSphere)														//球
	{
		DeleteGO(m_testSphere);
	}
	if (InitSprite)														//絵
	{
		DeleteGO(m_testSprite);
	}
	if (InitFont)														//文字
	{
		DeleteGO(m_testFont);
	}
	if (InitEfect)														//エフェクト
	{
		DeleteGO(m_testEfect);
	}
	if (InitSky)														//空
	{
		DeleteGO(m_testSky);
	}
	if (InitBGM)														//BGM
	{
		DeleteGO(m_testBGM);
	}
}

bool test::Start()
{
	if (InitBox)														//箱
	{
		m_testBox = NewGO<prefab::CSkinModelRender>(0);
		m_testBox->Init(L"modelData/testBox.cmo");						//書きたいモデルを呼ぶ
		m_testBox->SetPosition(m_3DPosition);							//位置を決める
		m_testBox->SetScale(m_BoxScale);								//大きさを決める
		m_testBox->SetRotation(m_Rotation);								//回転率を決める
	}
	if (InitSphere)														//球
	{
		m_testSphere = NewGO<prefab::CSkinModelRender>(0);
		m_testSphere->Init(L"modelData/testSphere.cmo");				//書きたいモデルを呼ぶ
		m_testSphere->SetPosition(m_3DPosition);							//位置を決める
		m_testSphere->SetScale(m_SphereScale);								//大きさを決める
		m_testSphere->SetRotation(m_Rotation);								//回転率を決める
	}
	if (InitSprite)														//絵
	{
		m_testSprite = NewGO<prefab::CSpriteRender>(0);
		m_testSprite->Init(L"sprite/空test.dds", 1280.0f, 720.0f, false);//書きたい絵を呼ぶ。同時に大きさを決める。trueにすると3D空間に表示される
		m_testSprite->SetPosition(m_SpritePosition);						//位置を決める
		m_testSprite->SetScale(m_Scale);								//大きさを決める
		m_testSprite->SetRotation(m_Rotation);							//回転率を決める
		m_testSprite->SetPivot(m_2DPivot);								//基点を決める
	}
	if (InitFont)														//文字
	{
		m_testFont = NewGO<prefab::CFontRender>(0);
		swprintf_s(testText, L"%d", testtext);							//textTextに文字を入力する
		m_testFont->SetText(testText);									//書きたい文字列を呼ぶ
		m_testFont->SetPosition(m_2DPosition);							//位置を決める
		m_testFont->SetPivot(m_2DPivot);								//基点を決める
		m_testFont->SetColor(m_Color);									//色を決める
		m_testFont->SetScale(1.0f);										//大きさを決める
		m_testFont->SetRotation(0.0f);									//回転率を決める
	}
	if (InitEfect)														//エフェクト
	{
		m_testEfect = NewGO<prefab::CEffect>(0);
		m_testEfect->Play(L"effect/test.efk");							//出したいエフェクトを呼ぶ
		m_testEfect->SetPosition(m_3DPosition);							//位置を決める
		m_testEfect->SetScale(m_Scale);									//大きさを決める
		m_testEfect->SetRotation(m_Rotation);							//回転率を決める
	}
	if (InitSky)														//空
	{
		m_testSky = NewGO<prefab::CSky>(0);
		m_testSky->SetPosition(m_3DPosition);							//位置を決める
		m_testSky->SetScale(m_Scale);									//大きさを決める
	}
	if (InitSE)															//SE
	{
		m_testSE = NewGO<prefab::CSoundSource >(0);
		m_testSE->Init(L"sound/coinGet.wav");							//音源を呼ぶ
		m_testSE->SetPosition(m_3DPosition);							//位置を決める。なくてもいい
		m_testSE->SetVolume(1.0f);										//音量
		m_testSE->Play(false);											//音がループするかどうか
	}
	if (InitBGM)														//BGM
	{	
		m_testBGM = NewGO<prefab::CSoundSource>(0);
		m_testBGM->Init(L"sound/bgm.wav");								//書きたいモデルを呼ぶ
		m_testBGM->SetPosition(m_3DPosition);							//位置を決める。なくてもいい
		m_testBGM->SetVolume(1.0f);										//音量
		m_testBGM->Play(true);											//音がループするかどうか
	}	
	if (InitPhysi)														//静的オブジェクト
	{
		m_testPhysics.SetPositionAndRotation(m_3DPosition, m_Rotation);	//静的オブジェクトができる(多分）
	}
	if (InitCharcon)													//キャラコン
	{
		m_Characon.Init(20.0f, 100.0f, m_3DPosition);					//キャラコンができる(多分）
	}
	return true;
}

void test::Update()
{
	CVector3 m_MoveSpeed = CVector3::Zero;
	if (InitCharcon)													//キャラコン
	{
		m_3DPosition = m_Characon.Execute(m_MoveSpeed);					//キャラコンが移動する(多分）
	}

	if (InitBGM)														//BGM
	{
		m_testBGM->SetPosition(m_3DPosition);							//位置を決める。
		m_testBGM->SetVolume(1.0f);										//音量
	}

	if (InitSky)														//空
	{
		m_testSky->SetPosition(m_3DPosition);							//位置を決める
		m_testSky->SetScale(m_Scale);									//大きさを決める
	}

	if (InitEfect)														//エフェクト
	{
		m_testEfect->SetPosition(m_3DPosition);							//位置を決める
		m_testEfect->SetScale(m_Scale);									//大きさを決める
		m_testEfect->SetRotation(m_Rotation);							//回転率を決める
	}

	if (InitFont)														//文字
	{
		swprintf_s(testText, L"%d", testtext);							//textTextに文字を入力する
		m_testFont->SetText(testText);									//書きたい文字列を呼ぶ
		m_testFont->SetPosition(m_2DPosition);							//位置を決める
		m_testFont->SetPivot(m_2DPivot);								//基点を決める
		m_testFont->SetColor(m_Color);									//色を決める
		m_testFont->SetScale(1.0f);										//大きさを決める
		m_testFont->SetRotation(0.0f);									//回転率を決める
	}

	if (InitSprite)														//絵
	{
		m_testSprite->SetPosition(m_SpritePosition);
		m_testSprite->SetScale(m_Scale);								//大きさを決める
		m_testSprite->SetRotation(m_Rotation);							//回転率を決める
		m_testSprite->SetPivot(m_2DPivot);								//基点を決める
	}

	if (InitSphere)														//球
	{
		m_testSphere->SetPosition(m_3DPosition);							//位置を決める
		m_testSphere->SetScale(m_SphereScale);									//大きさを決める	
		m_testSphere->SetRotation(m_Rotation);								//回転率を決める
	}

	if (InitBox)														//箱
	{
		m_testBox->SetPosition(m_3DPosition);							//位置を決める
		m_testBox->SetScale(m_BoxScale);									//大きさを決める
		m_testBox->SetRotation(m_Rotation);								//回転率を決める
	}
}