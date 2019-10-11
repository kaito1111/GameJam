#pragma once
#include "GameDelete.h"
#include "GameSence.h"

class buhin;
class Arm;
class ClaftScreen : public IGameObject
{
public:
	ClaftScreen();
	~ClaftScreen();

	bool Start();
	void Update();

	int BuhinCount1 = 0;
	int BuhinCount2 = 0;
	int BuhinCount3 = 0;
	int count = 0;

	float rot1 = 0.0f;	//��]��
	float rot2 = 50.0f;	//��]��


	bool hituyoubuhin1 = false;
	bool hituyoubuhin2 = false;
	bool Buhin1 = false;
	bool Buhin2 = false;
	bool GameOver = false;
	bool senni = false;

	void Query();
	void hituyoubuhin();
	void rotation();
	void claft();
	void sound();

	GameSence* GS = nullptr;	//�Q�[���V�[��
	GameDelete* GD = nullptr;	//�f���[�g�����I
	CQuaternion qrot = CQuaternion::Identity;
	CQuaternion qrot2 = CQuaternion::Identity;
	CQuaternion qRot;	//��]
	CQuaternion qRot2;	//��]
	CVector3 scale = CVector3::Zero;	//�X�v���C�g�̃X�P�[��
	CVector3 buhinscale = CVector3::One;	//�^�C���̃X�P�[��
	CVector3 buhinscale2 = CVector3::One;	//�O���̃X�P�[��
	prefab::CSpriteRender* m_spriteRender = nullptr;	//�N���t�g��ʂ̘g
	CVector3 m_position = CVector3::Zero;	//�N���t�g��ʂ̘g�̈ʒu
	prefab::CSpriteRender* m_hituyoubuhin1 = nullptr;	//�K�v�ȕ��i�̂P	
	CVector3 buhin1pos = CVector3::Zero;	//�K�v�ȕ��i�P�̈ʒu
	prefab::CSpriteRender* m_hituyoubuhin2 = nullptr;	//�K�v�ȕ��i�̂Q
	CVector3 buhin2pos = CVector3::Zero;	//�K�v�ȕ��i�Q�̈ʒu
	prefab::CSkinModelRender* m_BuhinModelRender1 = nullptr;	//�E��ɕ\�����镔�i�P
	CVector3 m_Buhin1pos = CVector3::Zero;	//�擾�������i�P�̈ʒu
	prefab::CSkinModelRender* m_BuhinModelRender2 = nullptr;	//�E��ɕ\�����镔�i�Q
	CVector3 m_Buhin2pos = CVector3::Zero;	//�擾�������i�Q�̈ʒu
	prefab::CSpriteRender* m_taiya = nullptr;	//�^�C���̃X�v���C�g
	CVector3 m_taiyapos = CVector3::Zero;	//�^�C���̃X�v���C�g�̈ʒu
	prefab::CSpriteRender* m_gaisou = nullptr;	//�O���̃X�v���C�g
	CVector3 m_gaisoupos = CVector3::Zero;	//�O���̃X�v���C�g�̈ʒu
	prefab::CSoundSource* m_bgmSoundSource = nullptr;	//BGM�p�̃T�E���h�\�[�X�B
	CVector3 effectpos = CVector3::Zero;	//�G�t�F�N�g�̃|�W�V����
};