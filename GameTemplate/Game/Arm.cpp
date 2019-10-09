#include "stdafx.h"
#include "Arm.h"
#include "Buhin.h"
#include "ClaftScreen.h"
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
	if (m_Claft->GameOver) {

		CVector3 m_MoveSpeed = CVector3::Zero;
		float DropTime = GameTime().GetFrameDeltaTime() * 100.0f;			//��̊�{�ɂȂ鎞��
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
		if (m_ArmPosition.x >= 600.0f)							//����ȏ㍶�ɍs����
		{
			m_ArmPosition.x = 600.0f;
			ArmDown = 0;
		}

		QueryGOs<Buhin>("Gomi", [&](Buhin* m_Gomi)->bool		//�S�~���E��
			{
				float ArmX = m_ArmPosition.x;
				float GomiX = m_Gomi->m_position.x;
				float hantei = GomiX - ArmX;
				if (fabsf(hantei <= 10.0f) && m_ArmPosition.y == -300.0f)
				{
					Catch = true;
				}
				if (Catch && HoldUp >= 1.0f)
				{
					m_Gomi->m_position.y += 20.0f;
				}
				return true;
			});
		QueryGOs<Buhin>("Buhin1", [&](Buhin* m_Buhin1)->bool	//�^�C�����E��
			{
				float ArmX = m_ArmPosition.x;
				float m_Buhin1X = m_Buhin1->m_position.x;
				float hantei = m_Buhin1X - ArmX;
				if (hantei <= 10.0f)
				{
					Catch = true;
				}
				if (Catch && HoldUp >= 1.0f)
				{
					m_Buhin1->m_position.y += 20.0f;
				}
				return true;
			});
		QueryGOs<Buhin>("Buhin2", [&](Buhin* m_Buhin2)->bool	//�t���[�����E��
			{
				float ArmX = m_ArmPosition.x;
				float m_Buhin2X = m_Buhin2->m_position.x;
				float hantei = m_Buhin2X - ArmX;
				if (hantei <= 10.0f)
				{
					Catch = true;
				}
				if (Catch && HoldUp >= 1.0f)
				{
					m_Buhin2->m_position.y += 20.0f;
				}
				return true;
			});
		if (Catch)												//������ǂ�����
		{
			HoldUp += GameTime().GetFrameDeltaTime();
		}


		m_ArmModel->SetPosition(m_ArmPosition);					//���f���Ɉʒu��`����
	}
}
