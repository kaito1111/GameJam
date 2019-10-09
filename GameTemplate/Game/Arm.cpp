#include "stdafx.h"
#include "Arm.h"
#include "Buhin.h"
#include "ClaftScreen.h"

Arm::Arm()
{
}

Arm::~Arm()
{
}

bool Arm::Start()
{
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);					//���f�����o����
	m_ArmModel->Init(L"modelData/unityChan.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);								//�ʒu���Z�b�g����
	m_ArmModel->SetScale(m_Scale * 2);									//�傫�����Z�b�g����
	m_Claft = FindGO<ClaftScreen>("cs");
	return true;
}

void Arm::Update()
{
	if (!m_Claft->GameOver) {

		CVector3 m_MoveSpeed = CVector3::Zero;
		float DropTime = GameTime().GetFrameDeltaTime() * 200.0f;			//��̊�{�ɂȂ鎞��
		if (Pad(0).IsPress(enButtonRight))									//�E�ɓ�����
		{
			m_MoveSpeed.x = -10.0f;
		}
		if (Pad(0).IsPress(enButtonLeft))									//���ɓ���
		{
			m_MoveSpeed.x = 10.0f;
		}
		if (Set && Pad(0).IsPress(enButtonB))								//���ɓ������ǂ����𔻒肷��
		{
			Set = false;
		}
		if (!Set)
		{
			m_MoveSpeed.y = -DropTime;							//���ɓ���
			if (ArmDown >= 1.0f)								//���ɂ��鎞��
			{
				m_MoveSpeed.y = DropTime;						//��ɏオ��
			}
			if (m_ArmPosition.y <= -300.0f)						//����ȏ㉺�ɍs����
			{
				m_ArmPosition.y = -300.0f;
				ArmDown += GameTime().GetFrameDeltaTime();
			}
		}

		m_ArmPosition += m_MoveSpeed;							//�������x���ʒu�ɂ���
		if (m_ArmPosition.x <= -50.0f)							//����ȏ�E�ɍs����
		{
			m_ArmPosition.x = -50.0f;
		}
		if (m_ArmPosition.x >= 300.0f)							//����ȏ㍶�ɍs����
		{
			m_ArmPosition.x = 300.0f;
		}
		if (m_ArmPosition.y >= 250.0f)						//����ȏ㉺�ɍs����
		{
			ArmDown = 0;
			m_ArmPosition.y = 250.0f;
			Set = true;
		}
		if (Catch)												//������ǂ�����
		{
			HoldUp += GameTime().GetFrameDeltaTime();
		}


	}
	m_ArmModel->SetPosition(m_ArmPosition);					//���f���Ɉʒu��`����
}
