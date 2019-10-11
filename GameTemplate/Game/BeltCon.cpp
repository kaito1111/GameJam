#include "stdafx.h"
#include "BeltCon.h"
#include "Buhin.h"
#include "tkEngine/timer/tkGameTime.h"
#include "GameSence.h"
#include "gear.h"

BeltCon::BeltCon()
{
}

BeltCon::~BeltCon()
{
	DeleteGO(ss);
	DeleteGO(m_skinModelRender);
}

bool BeltCon::Start()
{
	arm = FindGO<Arm>("Arm");
	//�f�[�^�̓ǂݍ���
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BeltC.cmo");
	m_Sence = FindGO< GameSence>("GameSence");
	//�T�E���h
	ss = NewGO<prefab::CSoundSource>(0);
	float vol = 0.5f;
	ss->Init(L"sound/Beltcon_Trim.wav");
	ss->SetVolume(vol);
	ss->Play(true);

	//�傫���̒���
	scale.x = 18.0f;
	scale.z = 2.0f;
	m_skinModelRender->SetScale(scale);

	//�ʒu�̒���
	m_position.y = -350.0f;
	m_skinModelRender->SetPosition(m_position);
	for (int i = 0; i < 5; i++)
	{
		char m_Name[128];
		sprintf_s(m_Name, "gear%d", i);
		NewGO<gear>(0, m_Name);
		m_gear[i] = FindGO<gear>(m_Name);
	}
	for (int i = 0; i < 5; i++)
	{

		m_gear[i]->m_Position = { 600.0f - (i * 300.0f),-450.0f,0.0f };
	}
	return true;
}

/*�������畔�i�������_���ɗ��������������Ă���
������X�Ŋ����Ăł��]��̒l�ɉ�����
�ǂ̕��i�𗬂��̂����肵�Ă���*/
//���΂����i1�A�����i2�A�����S�~
//Generator�݂����Ȋ���
void BeltCon::Update()
{
	//�N���t�g��ʂ��g�傳�ꂽ��BeltCon�����ɍ~��Ă��ď�����
	if (m_position.y <= -500) {
		DeleteGO(this);
	}
	//�A�[���������Ă�Ԃ̓T�E���h������
	if (arm->Set == true) {
		ss->Play(true);
	}
	else {
		ss->Stop();
	}

	//�o�ߎ���
	if (!m_Sence->GameOver && arm->Set == true)
	{
		m_timer += GameTime().GetFrameDeltaTime();
	}
	
	// m_timer > Xf ��X�̒l��������ƃX�|�[�����Ԃ��ς��܂�
	if (m_timer > 2.0f) {
		//����
		rand = Random().GetRandInt() % waru;
		//rand�̒l��waru�ɕ�����
		//rand = rand ;

		/*���ꂼ��̗����ɑΉ�����"���i"�̃C���X�^���X�������ō쐬���܂�
		"���i"��ǉ��������ꍇ��������Buhin.cpp�ɒǉ����Ă�������*/
		//�����ł��������Ȃ����邽�߂ɃR�[�h����₱�����ł����p�[�c�̃C���X�^���X������Ă��邾���ł�
		if(count[1] > 2 || rand == 1 && arm->Set == true) {
			rand = 1;
			NewGO<Buhin>(0, "Buhin2");
			m_timer = 0;
			//�ł��̂ŏ�����
			waru = waruh;
			count[0]++;
			count[1] = 0;
		}
		else if (count[0] > 2 || rand == 0 && arm->Set == true) {
			rand = 0;
			NewGO<Buhin>(0, "Buhin1");
			//�^�C�}�[��������
			m_timer = 0;
			//�ł��̂ŏ�����
			waru = waruh;
			count[1]++;
			count[0] = 0;
		}
		else if(arm->Set == true){
			NewGO<Buhin>(0, "Gomi");
			m_timer = 0;
			//�S�~���A���łłȂ��悤�ɒ���
			waru--;
		}
	}
}
