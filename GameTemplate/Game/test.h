#pragma once

#include "tkEngine/physics/tkPhysicsStaticObject.h"

class test : public IGameObject
{
public:
	test();
	~test();

	bool Start();
	void Update();

	void Seta(int set)
	{
		a = set;											//privateの変数を変更できる
	}
	int Geta()
	{
		return a;											//privateの変数を見れる
	}
	
	prefab::CSkinModelRender* m_testBox= nullptr;			//箱のモデルを出せる
	prefab::CSkinModelRender* m_testSphere = nullptr;		//球のモデルを出せる
	prefab::CSpriteRender* m_testSprite = nullptr;			//絵を出せる
	prefab::CFontRender* m_testFont = nullptr;				//文字を出せる
	prefab::CEffect* m_testEfect = nullptr;					//エフェクトを出せる
	prefab::CSky* m_testSky = nullptr;						//キューブマップを出せる
	prefab::CSoundSource* m_testSE = nullptr;				//SEを出せる
	prefab::CSoundSource* m_testBGM = nullptr;				//BGMを出せる
	CPhysicsStaticObject m_testPhysics;						//静的オブジェクト(動かないモデル）
	CCharacterController m_Characon;						//動的オブジェクト(動けるモデル）

	CVector2 m_2DPosition = CVector2::Zero;					//2Dのベクトル
	CVector3 m_3DPosition = CVector3::Zero;					//3Dのベクトル
	CVector3 m_SpritePosition = { -640.0f,-360.0f,0.0f };		//3Dのベクトル
	CQuaternion m_Rotation = CQuaternion::Identity;			//回転率
	CVector4 m_Color = CVector4::White;						//色(白）
	CVector3 m_BoxScale = { 1.5f,8.0f,1.5f };				//箱の大きさ
	CVector3 m_SphereScale = { 3.0f,3.0f,3.0f };			//球の大きさ
	CVector3 m_Scale = CVector3::One;						//大きさ
	CVector2 m_2DPivot = CVector2::Zero;					//2Dの基点

	wchar_t testText[128] = {};								//文字列(Fontで使っている）
	int testtext = 0;										//%dの部分に入る数字

	bool InitBox = false;									//trueになると箱が出る
	bool InitSphere = false;								//trueになると球が出る
	bool InitSprite = false;								//trueになると絵が出る
	bool InitFont = false;									//trueになると文字が出る
	bool InitEfect = false;									//trueになるとエフェクトが出る
	bool InitSky = false;									//trueになるとキューブマップが出る
	bool InitSE = false;									//trueになるとSEが出る
	bool InitBGM = false;									//trueになるとBGMが出る
	bool InitPhysi = false;									//trueになると静的オブジェクトがモデルに当てはまる
	bool InitCharcon = false;								//trueになるとキャラコンがモデルに当てはまる

private:
	int a = 0;												//ほかのクラスから見らない変数
};