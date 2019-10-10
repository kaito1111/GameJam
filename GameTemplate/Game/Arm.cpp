#include "stdafx.h"
#include "Arm.h"
#include "Buhin.h"
#include "ClaftScreen.h"

Arm::Arm()
{
}

Arm::~Arm()
{
	DeleteGO(m_ArmModel);
	DeleteGO(m_Claft);
	DeleteGO(m_ArmtumeRight);
	DeleteGO(m_ArmtumeLeft);
}

bool Arm::Start()
{
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);					//���f�����o����
	m_ArmModel->Init(L"modelData/arm_ude.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);								//�ʒu���Z�b�g����
	m_ArmModel->SetScale(m_Scale * 2);									//�傫�����Z�b�g����	
	m_ArmtumeRight = NewGO<prefab::CSkinModelRender>(0);
	m_ArmtumeRight->Init(L"modelData/arm_tume.cmo");
	m_TumePos = m_ArmPosition;
	m_TumePos.y = m_ArmPosition.y - 20.0f;
	m_ArmtumeRight->SetPosition(m_TumePos);
	m_ArmtumeRight->SetScale(m_Scale * 2);
	m_ArmtumeLeft = NewGO<prefab::CSkinModelRender>(0);
	m_ArmtumeLeft->Init(L"modelData/arm_tume.cmo");
	m_ArmtumeLeft->SetPosition(m_TumePos);
	m_ArmtumeLeft->SetScale(m_Scale * 2);
	m_Rot.SetRotationDeg(CVector3::AxisY, 180.0f);
	m_ArmtumeLeft->SetRotation(m_Rot);
	m_Claft = FindGO<ClaftScreen>("cs");

	m_Delete = FindGO<GameDelete>("GameDelete");
	return true;
}

void Arm::Update()
{
	if (m_Delete->DeleteArm)
	{
		DeleteGO(this);
	}
	CQuaternion m_ChechRotLeft = CQuaternion::Identity;
	CQuaternion m_ChechRotRight = CQuaternion::Identity;
	if (!m_Claft->GameOver)
	{
		if (Drop) {
			CVector3 m_MoveSpeed = CVector3::Zero;
			float DropTime = GameTime().GetFrameDeltaTime() * 200.0f;			//��̊�{�ɂȂ鎞��
			if (Set && Pad(0).IsPress(enButtonB))								//���ɓ������ǂ����𔻒肷��
			{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho1.wav");
					m_SS->Play(false);
					m_SS->SetVolume(0.005f);
				
				Set = false;
			}
			if (!Set)
			{
				m_MoveSpeed.y = -DropTime;							//���ɓ���
				if (ArmDown >= 1.0f)								//���ɂ��鎞��
				{
					m_MoveSpeed.y = DropTime;						//��ɏオ��
					if (!InitOto)
					{
						prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
						m_SS->Init(L"sound/arm_kouho1.wav");
						m_SS->Play(false);
						m_SS->SetVolume(0.0025f);
						InitOto = true;
					}
				}
				if (m_ArmPosition.y <= -150.0f)						//����ȏ㉺�ɍs����
				{
					m_ArmPosition.y = -150.0f;
					ArmDown += GameTime().GetFrameDeltaTime();
					Rotrate += 2.0f;
					InitOto = false;
				}
			}
			else
			{
				if (Pad(0).IsPress(enButtonRight))									//�E�ɓ�����
				{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho2.wav");
					m_SS->SetVolume(0.05f);
					m_MoveSpeed.x = -10.0f;
				}
				if (Pad(0).IsPress(enButtonLeft))									//���ɓ���
				{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho2.wav");
					/*m_SS->SetVolume(0.05f);*/
					m_MoveSpeed.x = 10.0f;
				}
			}
			m_ArmPosition += m_MoveSpeed;							//�������x���ʒu�ɂ���
			if (m_ArmPosition.x <= -50.0f)							//����ȏ�E�ɍs����
			{
				m_ArmPosition.x = -50.0f;
			}
			if (m_ArmPosition.x >= 600.0f)							//����ȏ㍶�ɍs����
			{
				m_ArmPosition.x = 600.0f;
			}
			if (!Catch)												//����ĂȂ�������
			{
				if (m_ArmPosition.y >= 200.0f)						//����ȏ��ɍs����
				{
					ArmDown = 0;
					m_ArmPosition.y = 200.0f;
					Set = true;
					Rotrate = 0.0f;
					InitOto = true;
				}
			}
			if (Rotrate >= 15.0f)
			{
				Rotrate = 15.0f;
			}

		}
	}
	m_ChechRotLeft.SetRotationDeg(CVector3::AxisZ, Rotrate);
	m_ChechRotRight.SetRotationDeg(CVector3::AxisZ, Rotrate);
	m_ChechRotLeft.Multiply(m_Rot);
	m_TumePos = m_ArmPosition;
	m_TumePos.y = m_ArmPosition.y - 20.0f;
	m_ArmtumeRight->SetPosition(m_TumePos);
	m_ArmtumeRight->SetRotation(m_ChechRotRight);
	m_ArmtumeLeft->SetPosition(m_TumePos);
	m_ArmtumeLeft->SetRotation(m_ChechRotLeft);
	m_ArmModel->SetPosition(m_ArmPosition);					//���f���Ɉʒu��`����
}
