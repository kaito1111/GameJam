#pragma once
#include "Arm.h"
class ClaftScreen;
class Buhin : public IGameObject
{
public:
	Buhin();
	~Buhin();
	bool Start();
	void Update();
	//�����o�ϐ�//
	//�N���X�ϐ�
	Arm* arm;
	//���f�������_�[
	prefab::CSkinModelRender* m_skinModelRender;
	//�N�I�[�^�j�I��
	CQuaternion qRot = CQuaternion::Identity;
	//���i�̍��W
	CVector3 m_position = CVector3::Zero;
	//����鑬��
	CVector3 m_moveSpeed = CVector3::Zero;
};

