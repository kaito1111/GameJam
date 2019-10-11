#pragma once
#include "GameDelete.h"

class ClaftScreen;
class GameSence;

class Arm : public IGameObject
{
public:
	Arm();
	~Arm();

	bool Start();
	void Update();

	prefab::CSkinModelRender* m_ArmModel = nullptr;				//�N���[���̘r�̃X�L�����f��
	prefab::CSkinModelRender* m_ArmtumeRight = nullptr;			//�N���[���̂߂̉E�̃X�L�����f��
	prefab::CSkinModelRender* m_ArmtumeLeft = nullptr;			//�N���[���̂߂̍��̃X�L�����f��
	ClaftScreen* m_Claft = nullptr;
	CVector3 m_ArmPosition = { 50.0f,300.0f,0.0f };				//�N���[���̃|�W�V����
	CVector3 m_TumePos = CVector3::Zero;						//�N���[���̂߂̃|�W�V����
	CVector3 m_Scale = CVector3::One;							//�N���[���̃T�C�Y
	bool Catch = false;											//���߂����ǂ����𔻒肷��
	bool Drop = false;											//
	bool Set = true;											//B�{�^����������悤�ɂ���
	float HoldUp = 0.0f;										//�����ŉ��ɂ��鎞��
	float ArmDown = 0.0f;										//���ɂ������鎞��
	float Rotrate = 0.0f;										//��]��
	bool InitOto = false;										//���ɍs�������o��
	CQuaternion m_Rot = CQuaternion::Identity;					//�߂𔽓]�������]
	GameDelete* m_Delete = nullptr;
	float MoveOto = 0.0f;										//�������̎���
	bool MoveSound = false;										//���������o��t���O
	GameSence* m_Senne = nullptr;
};