#pragma once
class ClaftScreen:public IGameObject
{
public:
	ClaftScreen();
	~ClaftScreen();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;

};

