#include "stdafx.h"
#include "BeltCon.h"

BeltCon::BeltCon()
{
}

BeltCon::~BeltCon()
{
}

bool BeltCon::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.FBX",0);
	return true;
}

void BeltCon::Update()
{
}