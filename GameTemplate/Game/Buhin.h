#pragma once
class Buhin : public IGameObject
{
public:
	Buhin();
	~Buhin();
	bool Start();
	void Update();
	//�����o�ϐ�//
	//���f�������_�[
	prefab::CSkinModelRender* m_skinModelRender;
	//���i�̍��W
	CVector3 m_position = CVector3::Zero;
	//����鑬��
	CVector3 m_moveSpeed = CVector3::Zero;
};
