#pragma once
class BeltCon : public IGameObject
{
public:
	BeltCon();
	~BeltCon();
	bool Start();
	void Update();
	//�����o�ϐ�//
	//���f�������_�[
	prefab::CSkinModelRender* m_skinModelRender;
};

