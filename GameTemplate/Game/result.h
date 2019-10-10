#pragma once
#include "GameDelete.h"
class result : public IGameObject
{
public:
	result();
	~result();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_SpriteTitle = nullptr;
	prefab::CSpriteRender* m_SpriteReStart = nullptr;
	prefab::CSpriteRender* m_SpriteSelect = nullptr;
	CVector3 m_TitlePosition = { -300.0f,-300.0f,0.0f };
	CVector3 m_ReStartPosition = { 300.0f,-300.0f,0.0f };
	CVector3 m_SelectPosition= { -300.0f,-300.0f,0.0f };
	float SpriteGO = 0.0f;
	bool New = false;
	prefab::CSpriteRender* m_Spritefade = nullptr;
	CVector4 m_Color = CVector4::White;
	CVector4 m_FadeColor = { 1.0f,1.0f,1.0f,0.0f };
	bool fadeout = false;

	GameDelete* m_GameDelete = nullptr;
};