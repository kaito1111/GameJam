#include "stdafx.h"
#include "Buhin.h"
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
	//�N���X�ϐ�
	BeltCon* belt;
	//Find
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
		m_skinModelRender->Init(L"modelData/buhin1.cmo");
	}
	else if (belt->rand == 1) {
		//buhin2�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/buhin2.cmo");
	}
	else {
		//�S�~�̃��f���f�[�^�̃��[�h
		m_skinModelRender->Init(L"modelData/Gomi.cmo");
	}

	m_skinModelRender->SetScale(Scale);

	//����鑬��
	m_moveSpeed.x = 2.5f;

	//���i���o�Ă��鏉���ʒu
	m_position.x = -700;
	m_position.y = -330;
	return true;
}

void Buhin::Update()
{
	//�E���獶�ɗ���
	m_position.x += m_moveSpeed.x;
	m_skinModelRender->SetPosition(m_position);

	//��ʊO�ɂł���폜
	if (m_position.x > 750) {
		DeleteGO(this);
	}
}
