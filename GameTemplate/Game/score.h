#pragma once
class score : public IGameObject
{
public:

	score();
	~score();

	bool Start();
	void Update();

	int Score = 0;
};
