#pragma once
#include "Arm.h"
#include "GameDelete.h"
class GameSence;
class BeltCon : public IGameObject
{
public:
	BeltCon();
	~BeltCon();
	bool Start();
	void Update();
	//�����o�ϐ�//
	//���f�������_�[
	prefab::CSkinModelRender* m_skinModelRender;
	//�T�E���h
	prefab::CSoundSource* ss;
	//�N���X�ϐ�
	Arm* arm;
	//�N���X�ϐ�
	GameDelete* GD;
	//�X�P�[��
	CVector3 scale;
	//���W
	CVector3 m_position = CVector3::Zero;
	//�^�C�}�[
	float m_timer = 0;
	//�����@Buhin�N���X�Ŏg�p����̂�.h�Œ�`
	int rand = 0;
	//waru �� waruh �̒l��������ƃS�~���ł銄����ς���܂�
	int waru = 5;
	//waruh�͏������p�Ȃ̂�cpp�ύX���Ȃ��ł��������B
	int waruh = 5;
	int count[2] = { 0,0 };
	GameSence* m_Sence = nullptr;
};

