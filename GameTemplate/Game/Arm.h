#pragma once
#include "GameDelete.h"

class ClaftScreen;

class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//�N���[���̘r�̃X�L�����f��
	prefab::CSkinModelRender* m_ArmtumeRight = nullptr;
	prefab::CSkinModelRender* m_ArmtumeLeft = nullptr;			
	ClaftScreen* m_Claft = nullptr;
	CVector3 m_ArmPosition = { 0.0f,200.0f,0.0f };				//�N���[���̃|�W�V����
	CVector3 m_TumePos = CVector3::Zero;
	CVector3 m_Scale = CVector3::One;							//�N���[���̃T�C�Y
	bool Catch = false;											//���߂����ǂ����𔻒肷��
	bool Drop = false;											//
	bool Set = true;											//B�{�^����������悤�ɂ���
	float HoldUp = 0.0f;										//�����ŉ��ɂ��鎞��
	float ArmDown = 0.0f;										//���ɂ������鎞��
	float Rotrate = 0.0f;
	CQuaternion m_Rot = CQuaternion::Identity;
	bool InitOto = false;
	GameDelete* m_Delete = nullptr;
};