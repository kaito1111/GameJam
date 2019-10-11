#include "stdafx.h"
#include "gear.h"

gear::gear()
{
}

gear::~gear()
{
	DeleteGO(m_GearModel);
}

bool gear::Start()
{
	m_GearModel = NewGO<prefab::CSkinModelRender>(0);
	m_GearModel->Init(L"modelData/gear.cmo");
	m_GearModel->SetPosition(m_Position);
	m_GearModel->SetScale(m_Scale);
	m_Rot.SetRotationDeg(CVector3::AxisX, 90.0f);
	m_GearModel->SetRotation(m_Rot);

	m_Delete = FindGO< GameDelete>("GameDelete");
	return true;
}

void gear::Update()
{
	CQuaternion m_Rot2 = CQuaternion::Identity;
	Rotritu -= 2.0;
	m_Rot.SetRotationDeg(CVector3::AxisY, Rotritu);
	m_Rot.Multiply(m_Rot2);
	m_GearModel->SetRotation(m_Rot);
	if (m_Delete->DeleteArm)
	{
		DeleteGO(this);
	}
}
