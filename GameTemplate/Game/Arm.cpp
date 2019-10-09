#include "stdafx.h"
#include "Arm.h"
#include "Buhin.h"

Arm::Arm()
{
}

Arm::~Arm()
{
}

bool Arm::Start()
{
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);
	m_ArmModel->Init(L"modelData/unityChan.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);
	m_ArmModel->SetScale(m_Scale * 2);
	return true;
}

void Arm::Update()
{
	CVector3 m_MoveSpeed = CVector3::Zero;
	if (Pad(0).IsPress(enButtonRight))
	{
		m_MoveSpeed.x = -10.0f;
	}
	if (Pad(0).IsPress(enButtonLeft))
	{
		m_MoveSpeed.x = 10.0f;
	}
	if (Set && Pad(0).IsPress(enButtonB))
	{
		m_MoveSpeed.y = -20.0f;
		Set = false;
	}
	if (ArmDown >= 1.0f)
	{
		m_ArmPosition.y += 40.0f;
	}
	m_ArmPosition += m_MoveSpeed;
	if (m_ArmPosition.x <= -50.0f)
	{
		m_ArmPosition.x = -50.0f;
	}
	if (m_ArmPosition.y <= -300.0f)
	{
		m_ArmPosition.y = -300.0f;
		ArmDown += GameTime().GetFrameDeltaTime();
	}
	QueryGOs<Buhin>("Gomi", [&](Buhin* m_Gomi)->bool
		{
			float ArmX = m_ArmPosition.x;
			float GomiX = m_Gomi->m_position.x;
			float hantei = GomiX - ArmX;
			if (hantei <= 10.0f)
			{
				Catch = true;
			}
			if (Catch && HoldUp >= 1.0f)
			{
				m_Gomi->m_position.y += 20.0f;
			}
			return true;
		});
	QueryGOs<Buhin>("buhin1", [&](Buhin* m_Gomi)->bool
		{
			float ArmX = m_ArmPosition.x;
			float GomiX = m_Gomi->m_position.x;
			float hantei = GomiX - ArmX;
			if (hantei <= 10.0f)
			{
				Catch = true;
			}
			if (Catch && HoldUp >= 1.0f)
			{
				m_Gomi->m_position.y += 20.0f;
			}
			return true;
		});
		QueryGOs<Buhin>("buhin2", [&](Buhin* m_Gomi)->bool
			{
				float ArmX = m_ArmPosition.x;
				float GomiX = m_Gomi->m_position.x;
				float hantei = GomiX - ArmX;
				if (hantei <= 10.0f)
				{
					Catch = true;
				}
				if (Catch && HoldUp >= 1.0f)
				{
					m_Gomi->m_position.y += 20.0f;
				}
				return true;
			});
	if (Catch)
	{
		HoldUp += GameTime().GetFrameDeltaTime();
	}

	m_ArmModel->SetPosition(m_ArmPosition);
}
