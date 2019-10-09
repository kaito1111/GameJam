#include "stdafx.h"
#include "Buhin.h"
#include "Arm.h"
#include "BeltCon.h"

Buhin::Buhin()
{
}

Buhin::~Buhin()
{
	DeleteGO(m_skinModelRender);
}

/*�N���X���g���܂킵�ł���悤�ɂ��邽��
�x���g�R���x�A����rand�̒l���Q�Ƃ���
����rand�ɑΉ��������f���f�[�^��ǂݍ��܂���*/

bool Buhin::Start()
{
	arm = FindGO<Arm>("Arm");
	//Find����BeltCon�̒l���Q�Ƃł���悤��
	belt = FindGO<BeltCon>("BC");
	//�x���g�R���x�A����rand�̒l���Q�Ƃ���
	int rand = belt->rand;

	//�傫���̒���
	CVector3 Scale;
	Scale.x = 5;
	Scale.y = 3;
	Scale.z = 3;

	//�X�L��
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	//"���i"��ǉ������炱����BeltCon.cpp�ɒǉ����Ă�������//
	//�x���g�R���x�A�N���X��buhin1�����ꂽ��
	if (belt->rand == 0) {
		//buhin1�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/wheel.cmo");
		//�傫��
		Scale.x = 3;
		Scale.y = 5;
		Scale.z = 5;
		m_skinModelRender->SetScale(Scale);

		//���W
		m_position.x = -700;
		m_position.y = -350;
		m_position.z = 0;

		//�p�x
		//qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
		m_skinModelRender->SetRotation(qRot);
	}
	else if (belt->rand == 1) {
		m_position.x = -700;
		m_position.y = -330;
		//buhin2�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/buhin2.cmo");
	}
	else {
		//�S�~�̃��f���f�[�^�̃��[�h
		m_position.x = -800;
		m_position.y = -330;
		m_skinModelRender->Init(L"modelData/Gomi.cmo");
	}

	m_skinModelRender->SetScale(Scale);

	//����鑬��
	m_moveSpeed.x = 2.5f;

	//���i���o�Ă��鏉���ʒu
	return true;
}

void Buhin::Update()
{
	//�N�G���ŃA�[���ɃL���b�`����Ă���̂��̔�����s��

	QueryGOs<Arm>("Arm", [&](Arm* arm)->bool {
		CVector3 diff = arm->m_ArmPosition - m_position;
		//�����蔻��
		if (diff.Length() < 80) {
			IsCatch = true;
			if (!IamGomi)
			{
				arm->Catch = true;
			}
			return false;
		}
		return true;
		});

	if (IsCatch == true) {
		//���i�̍������A�[���̍����ɑ�����
		m_position.y = arm->m_ArmPosition.y;
	}

	//��ʊO�ɂł���폜
	if (m_position.x > 750) {
		DeleteGO(this);
	}
	//�N���[���������Ă邠����
	if (arm->Set == false) {
		m_moveSpeed.x = 0.0f;
		belt->m_timer = 0;
	}
	else {
		m_moveSpeed.x = 2.5f;
	}
	//Y������ʊO�ɂȂ�Ƃ��̃I�u�W�F�N�g������
	//��600�ȉ��ɂ��Ȃ��ł���������
	if (m_position.y >= 650) {
		DeleteGO(this);
		arm->Catch = false;
	}
	else {
		//arm->Catch = false;
	}
	if (IamGomi && arm->m_ArmPosition.y >= 200)
	{
		m_position.y = -330.0f;
		IsCatch = false;
	}
	//�E���獶�ɗ���
	m_position.x += m_moveSpeed.x;
	m_skinModelRender->SetPosition(m_position);
}
