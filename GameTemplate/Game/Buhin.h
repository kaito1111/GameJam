#pragma once
#include "Arm.h"
#include "BeltCon.h"
#include "ClaftScreen.h"
class ClaftScreen;
class Buhin : public IGameObject
{
public:
	Buhin();
	~Buhin();
	bool Start();
	void Update();
	void hantei();
	//�����o�ϐ�//
	//�d�����p
	bool IamWheel = false;
	bool Iamframe = false;
	bool IamGomi = false;
	//�A�[���N���X
	Arm* arm;
	//�x���g�R���x�A�N���X
	BeltCon* belt;
	//�N���t�g�X�N���[���N���X
	ClaftScreen* CS;
	//���f�������_�[
	prefab::CSkinModelRender* m_skinModelRender;
	//���܂ꂽ����
	bool IsCatch = false;
	//�N�I�[�^�j�I��
	CQuaternion qRot = CQuaternion::Identity;
	//���i�̍��W
	CVector3 m_position = CVector3::Zero;
	//����鑬��
	CVector3 m_moveSpeed = CVector3::Zero;
	int rand;
};

