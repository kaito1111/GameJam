#include "stdafx.h"
#include "Arm.h"
#include "Buhin.h"
#include "ClaftScreen.h"
#include "GameSence.h"

Arm::Arm()
{
}

Arm::~Arm()
{
	DeleteGO(m_ArmModel);
	DeleteGO(m_ArmtumeRight);
	DeleteGO(m_ArmtumeLeft);
}

bool Arm::Start()
{
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);		//�N���[���̘r�̃��f�����o����
	m_ArmModel->Init(L"modelData/arm_ude.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);					//�ʒu���Z�b�g����
	m_ArmModel->SetScale(m_Scale * 2);						//�傫�����Z�b�g����	
	m_ArmtumeRight = NewGO<prefab::CSkinModelRender>(0);	//�N���[���̂߂̉E�̃��f�����o����
	m_ArmtumeRight->Init(L"modelData/arm_tume.cmo");
	m_TumePos = m_ArmPosition;
	m_TumePos.y = m_ArmPosition.y - 20.0f;
	m_ArmtumeRight->SetPosition(m_TumePos);					//�N���[���̂߂̉E�̃|�W�V������������
	m_ArmtumeRight->SetScale(m_Scale * 2);					//�N���[���̂߂̉E�̃X�P�[����������
	m_ArmtumeLeft = NewGO<prefab::CSkinModelRender>(0);		//�N���[���̂߂̍��̃X�L�����f��
	m_ArmtumeLeft->Init(L"modelData/arm_tume.cmo");
	m_ArmtumeLeft->SetPosition(m_TumePos);					//�N���[���̂߂̍��̃|�W�V������������
	m_ArmtumeLeft->SetScale(m_Scale * 2);					//�N���[���̂߂̍��̃X�P�[����������
	m_Rot.SetRotationDeg(CVector3::AxisY, 180.0f);			//�N���[���̂߂̍��𔽓]����
	m_ArmtumeLeft->SetRotation(m_Rot);						//�N���[���̂߂̍��̔��]������������

	m_Senne = FindGO< GameSence>("GameSence");
	m_Claft = FindGO<ClaftScreen>("cs");
	m_Delete = FindGO<GameDelete>("GameDelete");
	return true;
}

void Arm::Update()
{
	CVector3 m_MoveSpeed = CVector3::Zero;
	if (m_Delete->DeleteArm)
	{
		DeleteGO(this);
	}
	MoveOto += GameTime().GetFrameDeltaTime();
	if (MoveOto >= 1.0f)
	{
		MoveSound = true;
	}
	CQuaternion m_ChechRotLeft = CQuaternion::Identity;				//�߂̍��̉�]��
	CQuaternion m_ChechRotRight = CQuaternion::Identity;			//�߂̉E�̉�]��
	if (!m_Claft->GameOver)
	{
		if (Drop)													//������悤�ɂ���
		{
			float DropTime = GameTime().GetFrameDeltaTime() * 200.0f;//��̊�{�ɂȂ鎞��
			if (Set && Pad(0).IsPress(enButtonB))					//���ɓ������ǂ����𔻒肷��
			{
				prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);			//���ɓ�������ǉ�����
				m_SS->Init(L"sound/arm_kouho1.wav");
				m_SS->Play(false);
				m_SS->SetVolume(0.5f);

				Set = false;
			}
			if (!Set)												//�����Ȃ������Ƃ�
			{
				m_MoveSpeed.y = -DropTime;							//���ɓ���
				if (m_ArmPosition.y <= -100.0f)						//����ȏ㉺�ɍs����
				{
					m_ArmPosition.y = -100.0f;
					ArmDown += GameTime().GetFrameDeltaTime();
					Rotrate += 2.0f;
					InitOto = false;
				}
				if (ArmDown >= 1.0f)								//���ɂ��鎞��
				{
					m_MoveSpeed.y = DropTime;						//��ɏオ��
					if (!InitOto)									//�����o���
					{
						prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
						m_SS->Init(L"sound/arm_kouho1.wav");
						m_SS->Play(false);
						m_SS->SetVolume(0.5f);
						InitOto = true;
					}
				}
			}
			else
			{
				if (Pad(0).IsPress(enButtonRight))					//�E�ɓ�����
				{
					m_MoveSpeed.x = -10.0f;
					if (MoveSound)
					{
						prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
						m_SS->Init(L"sound/arm_ugoku_kouho2.wav");
						m_SS->SetVolume(0.5f);
						m_SS->Play(false);
						MoveSound = false;
						MoveOto = 0.0f;
					}
				}
				if (Pad(0).IsPress(enButtonLeft))					//���ɓ���
				{
					m_MoveSpeed.x = 10.0f;
					if (MoveSound)
					{
						prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);			//�����o���
						m_SS->Init(L"sound/arm_ugoku_kouho2.wav");
						m_SS->SetVolume(0.5f);
						m_SS->Play(false);
						MoveSound = false;
						MoveOto = 0.0f;
					}
				}
			}							//�������x���ʒu�ɂ���
			if (m_ArmPosition.x < 50.0f)							//����ȏ�E�ɍs����
			{
				m_ArmPosition.x = 50.0f;
			}
			if (m_ArmPosition.x > 480.0f)							//����ȏ㍶�ɍs����
			{
				m_ArmPosition.x = 480.0f;
			}
			if (!Catch)												//����ĂȂ�������
			{
				if (m_ArmPosition.y >= 300.0f)						//����ȏ��ɍs����
				{
					ArmDown = 0;
					m_ArmPosition.y = 300.0f;
					Set = true;
					Rotrate = 0.0f;
					InitOto = true;
				}
			}
			if (Rotrate >= 15.0f)									//����ȏ��]�������
			{
				Rotrate = 15.0f;
			}

		}
	}
	if (m_Senne->GameOver)
	{
		m_MoveSpeed = { 0.0f,0.0f,0.0f };
	}
	m_ArmPosition += m_MoveSpeed;
	m_ChechRotLeft.SetRotationDeg(CVector3::AxisZ, Rotrate);		//�߂̍��̉�]�����Z�b�g����
	m_ChechRotRight.SetRotationDeg(CVector3::AxisZ, Rotrate);		//�߂̉E�̉�]�����Z�b�g����
	m_ChechRotLeft.Multiply(m_Rot);									//�߂̍��̉�]���𔽓]������
	m_TumePos = m_ArmPosition;
	m_TumePos.y = m_ArmPosition.y - 20.0f;
	m_ArmtumeRight->SetPosition(m_TumePos);							//�߂̉E�̈ʒu��͂���
	m_ArmtumeRight->SetRotation(m_ChechRotRight);					//�߂̉E�̉�]����͂���
	m_ArmtumeLeft->SetPosition(m_TumePos);							//�߂̍��̈ʒu��͂���
	m_ArmtumeLeft->SetRotation(m_ChechRotLeft);						//�߂̍��̈ʒu��͂���
	m_ArmModel->SetPosition(m_ArmPosition);							//���f���Ɉʒu��`����
}
