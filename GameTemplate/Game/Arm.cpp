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
		m_MoveSpeed.y = -GameTime().GetFrameDeltaTime();
		Set = false;
	}
	if (!Set)
	{
		m_MoveSpeed.y = -GameTime().GetFrameDeltaTime();
		if (ArmDown >= 1.0f)
		{
			m_MoveSpeed.y = GameTime().GetFrameDeltaTime();
		}
		if (m_ArmPosition.y >= 200.0f)
		{
			Set = true;
		}
	}
	m_ArmPosition += m_MoveSpeed;
	if (m_ArmPosition.x <= -50.0f)
	{
		m_ArmPosition.x = -50.0f;
	}
	if (m_ArmPosition.x >= 600.0f)
	{
		m_ArmPosition.x = 600.0f;
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
			if (hantei <= 10.0f&& hantei >= -10.0f)
			{
				Catch = true;
			}
			if (Catch && HoldUp >= 1.0f)
			{
				m_Gomi->m_position.y += 20.0f;
			}
			return true;
		});
	QueryGOs<Buhin>("Buhin1", [&](Buhin* m_Buhin1)->bool
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
		QueryGOs<Buhin>("Buhin2", [&](Buhin* m_Buhin2)->bool
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
	if (Catch)
	{
		HoldUp += GameTime().GetFrameDeltaTime();
	}

	m_ArmModel->SetPosition(m_ArmPosition);
}
