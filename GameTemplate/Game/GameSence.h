#pragma once
class GameSence : public IGameObject
{
public:

	GameSence();
	~GameSence();

	bool Start();
	void Update();

	prefab::CFontRender* m_TimerFont = nullptr;
	CVector3 m_Position = CVector3::Zero;
	wchar_t timer[128];
	float time = 120.0f;
	bool New = false;
	bool GameOver = false;
};
