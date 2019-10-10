#pragma once
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

};