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
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);					//モデルを出した
	m_ArmModel->Init(L"modelData/unityChan.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);								//位置をセットした
	m_ArmModel->SetScale(m_Scale * 2);									//大きさをセットした
	m_Claft = FindGO<ClaftScreen>("cs");
	return true;
}

void Arm::Update()
{
	if (!m_Claft->GameOver) {

		CVector3 m_MoveSpeed = CVector3::Zero;
		float DropTime = GameTime().GetFrameDeltaTime() * 200.0f;			//大体基本になる時間
		if (Pad(0).IsPress(enButtonRight))									//右に動かす
		{
			m_MoveSpeed.x = -10.0f;
		}
		if (Pad(0).IsPress(enButtonLeft))									//左に動く
		{
			m_MoveSpeed.x = 10.0f;
		}
		if (Set && Pad(0).IsPress(enButtonB))								//下に動くかどうかを判定する
		{
			Set = false;
		}
		if (!Set)
		{
			m_MoveSpeed.y = -DropTime;							//下に動く
			if (ArmDown >= 1.0f)								//下にいる時間
			{
				m_MoveSpeed.y = DropTime;						//上に上がる
			}
			if (m_ArmPosition.y <= -300.0f)						//それ以上下に行くな
			{
				m_ArmPosition.y = -300.0f;
				ArmDown += GameTime().GetFrameDeltaTime();
			}
		}

		m_ArmPosition += m_MoveSpeed;							//動く速度を位置にたす
		if (m_ArmPosition.x <= -50.0f)							//それ以上右に行くな
		{
			m_ArmPosition.x = -50.0f;
		}
		if (m_ArmPosition.x >= 300.0f)							//それ以上左に行くな
		{
			m_ArmPosition.x = 300.0f;
		}
		if (m_ArmPosition.y >= 250.0f)						//それ以上下に行くな
		{
			ArmDown = 0;
			m_ArmPosition.y = 250.0f;
			Set = true;
		}
		if (Catch)												//取ったどおおお
		{
			HoldUp += GameTime().GetFrameDeltaTime();
		}


	}
	m_ArmModel->SetPosition(m_ArmPosition);					//モデルに位置を伝える
}
