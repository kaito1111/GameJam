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

	prefab::CFontRender* m_TimerFont = nullptr;						//時間のフォント
	CVector2 m_FontPosition = { -600.0f,300.0f };					//フォントの文字
	CVector4 m_Color = CVector4::White;					//フォントのカラー
	wchar_t timer[128];
	float time = 120.0f;
	bool New = false;					//
	bool GameOver = false;					//
	GameDelete* m_Delete = nullptr;					
	prefab::CSpriteRender* m_Spritefade = nullptr;					//フェードの絵
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,1.0f };					//フェードの色
	float StartGame = 0.0f; 					//ゲームが始まる
	Arm* m_Arm = nullptr;
	bool move = false; 					//アームを動かすのを許可する
	prefab::CSoundSource* m_BGM = nullptr;					//BGMを出す
};
