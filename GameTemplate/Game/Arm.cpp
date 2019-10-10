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
	m_ArmModel = NewGO < prefab::CSkinModelRender>(0);					//モデルを出した
	m_ArmModel->Init(L"modelData/arm_ude.cmo");
	m_ArmModel->SetPosition(m_ArmPosition);								//位置をセットした
	m_ArmModel->SetScale(m_Scale * 2);									//大きさをセットした	
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
			float DropTime = GameTime().GetFrameDeltaTime() * 200.0f;			//大体基本になる時間
			if (Set && Pad(0).IsPress(enButtonB))								//下に動くかどうかを判定する
			{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho1.wav");
					m_SS->Play(false);
					m_SS->SetVolume(0.005f);
				
				Set = false;
			}
			if (!Set)
			{
				m_MoveSpeed.y = -DropTime;							//下に動く
				if (ArmDown >= 1.0f)								//下にいる時間
				{
					m_MoveSpeed.y = DropTime;						//上に上がる
					if (!InitOto)
					{
						prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
						m_SS->Init(L"sound/arm_kouho1.wav");
						m_SS->Play(false);
						m_SS->SetVolume(0.0025f);
						InitOto = true;
					}
				}
				if (m_ArmPosition.y <= -150.0f)						//それ以上下に行くな
				{
					m_ArmPosition.y = -150.0f;
					ArmDown += GameTime().GetFrameDeltaTime();
					Rotrate += 2.0f;
					InitOto = false;
				}
			}
			else
			{
				if (Pad(0).IsPress(enButtonRight))									//右に動かす
				{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho2.wav");
					m_SS->SetVolume(0.05f);
					m_MoveSpeed.x = -10.0f;
				}
				if (Pad(0).IsPress(enButtonLeft))									//左に動く
				{
					prefab::CSoundSource* m_SS = NewGO<prefab::CSoundSource>(0);
					m_SS->Init(L"sound/arm_kouho2.wav");
					/*m_SS->SetVolume(0.05f);*/
					m_MoveSpeed.x = 10.0f;
				}
			}
			m_ArmPosition += m_MoveSpeed;							//動く速度を位置にたす
			if (m_ArmPosition.x <= -50.0f)							//それ以上右に行くな
			{
				m_ArmPosition.x = -50.0f;
			}
			if (m_ArmPosition.x >= 600.0f)							//それ以上左に行くな
			{
				m_ArmPosition.x = 600.0f;
			}
			if (!Catch)												//取ってないおおお
			{
				if (m_ArmPosition.y >= 200.0f)						//それ以上上に行くな
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
	m_ArmModel->SetPosition(m_ArmPosition);					//モデルに位置を伝える
}
