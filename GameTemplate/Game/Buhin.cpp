#include "stdafx.h"
#include "Buhin.h"
#include "Arm.h"
#include "ClaftScreen.h"
#include "BeltCon.h"
#include "GameSence.h"

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
	CS = FindGO<ClaftScreen>("cs");
	//Find����BeltCon�̒l���Q�Ƃł���悤��
	belt = FindGO<BeltCon>("BC");
	m_Sence = FindGO<GameSence>("GameSence");
	//�x���g�R���x�A����rand�̒l���Q�Ƃ���
	rand = belt->rand;
	hantei();

	//�傫���̏�����
	Scale.x = 1;
	Scale.y = 1;
	Scale.z = 1;

	//�X�L��
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);

	//"���i"��ǉ������炱����BeltCon.cpp�ɒǉ����Ă�������//
	//�x���g�R���x�A�N���X��buhin1�����ꂽ��
	//�ԗւȂ�
	if (IamWheel == 1) {
		//�傫��
		Scale.z = 4;
		Scale.y = 4;
		m_skinModelRender->SetScale(Scale);

		//���W
		m_position.x = -800;
		m_position.y = -280;

		//�p�x
		qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
		m_skinModelRender->SetRotation(qRot);

		//buhin1�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/wheel.cmo");
	}
	//�t���[���Ȃ�
	else if (Iamframe == 1) {
		//���W
		m_position.x = -800;
		m_position.y = -320;
		
		//�傫��
		Scale.x = 1;
		Scale.y = 1;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//buhin2�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/body.cmo");
	}
	//�S�~�Ȃ�
	else if(IamGomi == 1){

		//���W
		m_position.x = -800;
		m_position.y = -330;

		//�傫��
		Scale.x = 2;
		Scale.y = 2;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//�S�~�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/garakuta1.cmo");
	}
	//���Ȃ�
	else if (IamGomi2 == 1) {
		//���W
		m_position.x = -800;
		m_position.y = -350;

		//�傫��
		Scale.x = 1;
		Scale.y = 1;
		Scale.z = 1;
		m_skinModelRender->SetScale(Scale);

		//�S�~�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/garakuta2.cmo");
	}

	//����鑬��
	m_moveSpeed.x = 2.5f;

	//���i���o�Ă��鏉���ʒu
	return true;
}

void Buhin::Update()
{

	//�N�G���ŃA�[���ɃL���b�`����Ă���̂��̔�����s��
	QueryGOs<Arm>("Arm", [&](Arm* arm)->bool {
		CVector3 diff;
		diff.y = arm->m_ArmPosition.y - m_position.y;
		/*dif.y�����̕������������邱�Ƃœ�����X���̓����蔻��͂��̂܂܂�
		Y���̓����蔻��𖳗����L�߂�*/
		//Y���̓����蔻��𒲐�
		if (IamGomi2 == 1) {
			diff.y -= 180;
		}
		else if(Iamframe == 1){
			diff.y -= 120;
		}
		else {
			diff.y -= 150;
		}
		diff.x = arm->m_ArmPosition.x - m_position.x;
		//�����蔻���傫������Ƃ��͂����𒲐�
		if (diff.Length() < 100) {
			//�A�[���̘r���܂�������L���b�`�t���O�𗧂Ă�
			if (arm->Rotrate >= 15.0f) {
				//�Ƃ肠�����L���b�`
				IsCatch = true;
			}
			if (IamWheel == 1 && CS->BuhinCount1 == 0 ||
				Iamframe == 1 && CS->BuhinCount2 == 0)
			{
				//���ꂪ�K�v�ȃp�[�c�Ȃ�Ƃ�
				arm->Catch = true;
			}
			return false;
		}
		return true;
	});

	//�������̂�����ł���Ȃ��
	if (IsCatch == true) {
		if (IamGomi2 == 1) {
			m_position.y = arm->m_ArmPosition.y - 220;
			m_position.x = arm->m_ArmPosition.x;
		}
		else if (Iamframe == 1) {
			m_position.y = arm->m_ArmPosition.y - 210;
			m_position.x = arm->m_ArmPosition.x;
		}
		else {
			//���i�̍������A�[���̍����ɑ�����
			//�A�[���̃��f�����ς�邽��y��-Y���Ă�������
			m_position.y = arm->m_ArmPosition.y - 190;
			m_position.x = arm->m_ArmPosition.x;
		}
	}
	//����Ȃ��p�[�c�Ȃ�
	if (arm->Catch == false) {
		if (arm->m_ArmPosition.y >= 300)
		{
			if (IamWheel == 1) {
				//�x���g�R���x�A�ɖ߂�
				m_position.y = -280.0f;
			}
			else if (Iamframe == 1) {
				m_position.y = -320.0f;
			}
			else if (IamGomi == 1) {
				m_position.y = -330.0f;
			}
			else {
				m_position.y = -350.0f;
			}
			//���������ĂȂ�
			IsCatch = false;
		}
	}

	//Y������ʊO�ɂȂ�Ƃ��̃I�u�W�F�N�g������
	//��600�ȉ��ɂ��Ȃ��ł���������
	if (m_position.y >= 650) {
		DeleteGO(this);
		//���������ĂȂ�
		arm->Catch = false;
	}

	//�N���[���������Ă邠����
	if (arm->Set == false) {
		m_moveSpeed.x = 0.0f;
		belt->m_timer = 0;
	}
	//�N���[���������Ă��Ȃ��Ȃ�
	else {
		m_moveSpeed.x = 2.5f;
	}

	//�E���獶�ɗ���
	m_position.x += m_moveSpeed.x;
	if (!m_Sence->GameOver)
	{
		m_skinModelRender->SetPosition(m_position);
	}
	

	//��ʊO�ɂł���폜
	if (m_position.x > 1000) {
		DeleteGO(this);
	}
}

//BeltCon�Ő������ꂽ���������Ƃ�
//���ꂪ�ǂ̕��i�Ȃ̂����d��������֐�
void Buhin::hantei() {
	if (rand == 0) {
		//�ԗ�
		IamWheel = 1;
	}
	else if (rand == 1) {
		//�t���[��
		Iamframe = 1;
	}
	else if(rand <= 2){
		//�S�~
		IamGomi = 1;
	}
	else {
		IamGomi2 = 1;
	}
}
