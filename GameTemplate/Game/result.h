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
	CVector3 m_TitlePosition = { -200.0f,-200.0f,0.0f };
	CVector3 m_ReStartPosition = { 200.0f,-200.0f,0.0f };
	CVector3 m_SelectPosition= { -200.0f,-200.0f,0.0f };

};