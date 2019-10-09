#pragma once
class result : public IGameObject
{
public:
	result();
	~result();

	bool Start();
	void Update();

	prefab::CSpriteRender* m_Sprite = nullptr;
	//prefab::CSpriteRender* m_Sprite = nullptr;
	CVector3 m_Position = CVector3::Zero;
};