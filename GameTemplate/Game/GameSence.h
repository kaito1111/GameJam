#pragma once
#include "GameDelete.h"
class Arm;
class GameSence : public IGameObject
{
public:

	GameSence();
	~GameSence();

	bool Start();
	void Update();

	prefab::CFontRender* m_TimerFont = nullptr;		//時間のフォント
	CVector2 m_FontPosition = { -600.0f,300.0f };	//フォントの文字
	CVector4 m_Color = CVector4::White;				//フォントのカラー
	wchar_t timer[128];
	float time = 30.0f;
	bool New = false;								//リザルトを出すよ
	bool GameOver = false;							//ゲームが強制的に終了するよ
	GameDelete* m_Delete = nullptr;					
	float StartGame = 0.0f; 						//ゲームが始まる
	Arm* m_Arm = nullptr;
	prefab::CSoundSource* m_BGM = nullptr;			//BGMを出す
};
