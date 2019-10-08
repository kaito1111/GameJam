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
//Generator�݂����Ȋ���
void BeltCon::Update()
{
	//�o�ߎ���
	m_timer += GameTime().GetFrameDeltaTime();
	// m_timer > Xf ��X�̒l��������ƃX�|�[�����Ԃ��ς��܂�
	if (m_timer > 2.0f) {
		//����
		rand = Random().GetRandInt();
		// %X ��������ƃS�~���ł銄����ς���܂�
		rand = rand % 10;

		/*���ꂼ��̗����ɑΉ�����"���i"�̃C���X�^���X�������ō쐬���܂�
		"���i"��ǉ��������ꍇ��������Buhin.cpp�ɒǉ����Ă�������*/
		if (rand == 0) {
			NewGO<Buhin>(0, "Buhin1");
			//�^�C�}�[��������
			m_timer = 0;
		}
		else if(rand == 1){
			NewGO<Buhin>(0, "Buhin2");
			m_timer = 0;
		}
		else {
			NewGO<Buhin>(0, "Gomi");
			m_timer = 0;
		}
	}
}
