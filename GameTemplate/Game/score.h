#pragma once
#include "GameDelete.h"

class GameSence;

class score : public IGameObject
{
public:

	score();
	~score();

	bool Start();
	void Update();

	GameSence* m_Sence = nullptr;	
	prefab::CFontRender* m_scoreFont = nullptr;				//時間のフォント
	int Score = 0;				//クリアした時間
	CVector3 m_FontColor = CVector3::One;				//フォントの文字
	wchar_t ScoreMoji[128];				//文字列
	CVector2 m_FontPosition = { -200.0f,200.0f };				//フォントの位置
	GameDelete* m_Delete = nullptr;
};
