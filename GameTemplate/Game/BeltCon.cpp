#include "stdafx.h"
#include "BeltCon.h"
#include "Buhin.h"
#include "tkEngine/timer/tkGameTime.h"

BeltCon::BeltCon()
{
}

BeltCon::~BeltCon()
{
}

bool BeltCon::Start()
{
	arm = FindGO<Arm>("Arm");
	//�f�[�^�̓ǂݍ���
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.cmo");

	//�傫���̒���
	scale.x = 18.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//�ʒu�̒���
	m_position.y = -350.0f;
	m_skinModelRender->SetPosition(m_position);


	return true;
}

/*�������畔�i�������_���ɗ��������������Ă���
������X�Ŋ����Ăł��]��̒l�ɉ�����
�ǂ̕��i�𗬂��̂����肵�Ă���*/
//���΂����i1�A�����i2�A�����S�~
//Generator�݂����Ȋ���
void BeltCon::Update()
{
	//�o�ߎ���
	m_timer += GameTime().GetFrameDeltaTime();
	// m_timer > Xf ��X�̒l��������ƃX�|�[�����Ԃ��ς��܂�
	if (m_timer > 2.0f) {
		//����
		rand = Random().GetRandInt();
		//rand�̒l��waru�ɕ�����
		rand = rand % waru;

		/*���ꂼ��̗����ɑΉ�����"���i"�̃C���X�^���X�������ō쐬���܂�
		"���i"��ǉ��������ꍇ��������Buhin.cpp�ɒǉ����Ă�������*/
		if (rand == 0 && arm->Set == true) {
			NewGO<Buhin>(0, "Buhin1");
			//�^�C�}�[��������
			m_timer = 0;
			//�ł��̂ŏ�����
			waru = waruh;
		}
		else if(rand == 1 && arm->Set == true){
			NewGO<Buhin>(0, "Buhin2");
			m_timer = 0;
			//�ł��̂ŏ�����
			waru = waruh;
		}
		else if(arm->Set == true){
			NewGO<Buhin>(0, "Gomi");
			m_timer = 0;
			Buhin* m_Gomi = FindGO<Buhin>("Gomi");
			m_Gomi->IamGomi = true;
			//�S�~���A���łłȂ��悤�ɒ���
			waru--;
		}
	}
}
