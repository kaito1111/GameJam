#pragma once
class GameSence : public IGameObject
{
public:

	GameSence();
	~GameSence();

	bool Start();
	void Update();

	prefab::CFontRender* m_TimerFont = nullptr;
	CVector2 m_FontPosition = { -600.0f,300.0f };
	CVector4 m_Color = CVector4::White;
	wchar_t timer[128];
	float time = 120.0f;
	bool New = false;
	bool GameOver = false;
};
