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
	//�X�P�[��
	CVector3 scale;
	//���W
	CVector3 m_position = CVector3::Zero;
	//�^�C�}�[
	float m_timer = 0;
	int rand = 0;
};

