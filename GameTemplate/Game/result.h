#pragma once
#include "GameDelete.h"
class result : public IGameObject
{
public:
	result();
	~result();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_SpriteTitle = nullptr;					//タイトルへ戻る絵
	prefab::CSpriteRender* m_SpriteReStart = nullptr;				//リスタートする絵
	prefab::CSpriteRender* m_SpriteSelect = nullptr;				//選択する絵
	CVector3 m_TitlePosition = { -300.0f,-300.0f,0.0f };			//タイトルのポジション
	CVector3 m_ReStartPosition = { 300.0f,-300.0f,0.0f };			//リスタートのポジション
	CVector3 m_SelectPosition= { -300.0f,-300.0f,0.0f };			//選択するポジション
	float SpriteGO = 0.0f;				//絵が表示させるまでの時間
	bool New = false;				//絵NewGOされる
	prefab::CSpriteRender* m_Spritefade = nullptr;				//フェードの絵
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,0.0f };				//フェードのカラー
	bool fadeout = false;				//フェードの絵をセットする絵
	bool restart = false;
	bool title = false;
	bool Newgo = false;

	GameDelete* m_GameDelete = nullptr;
};