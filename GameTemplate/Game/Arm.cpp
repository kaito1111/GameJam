#include "stdafx.h"
#include "Arm.h"

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

	return true;
}

void Arm::Update()
{
	if(Pad(0).is)
}
