#pragma once

#include "tkEngine/physics/tkPhysicsStaticObject.h"

class test : public IGameObject
{
public:
	test();
	~test();

	bool Start();
	void Update();

	void Seta(int set)
	{
		a = set;											//private�̕ϐ���ύX�ł���
	}
	int Geta()
	{
		return a;											//private�̕ϐ��������
	}
	
	prefab::CSkinModelRender* m_testBox= nullptr;			//���̃��f�����o����
	prefab::CSkinModelRender* m_testSphere = nullptr;		//���̃��f�����o����
	prefab::CSpriteRender* m_testSprite = nullptr;			//�G���o����
	prefab::CFontRender* m_testFont = nullptr;				//�������o����
	prefab::CEffect* m_testEfect = nullptr;					//�G�t�F�N�g���o����
	prefab::CSky* m_testSky = nullptr;						//�L���[�u�}�b�v���o����
	prefab::CSoundSource* m_testSE = nullptr;				//SE���o����
	prefab::CSoundSource* m_testBGM = nullptr;				//BGM���o����
	CPhysicsStaticObject m_testPhysics;						//�ÓI�I�u�W�F�N�g(�����Ȃ����f���j
	CCharacterController m_Characon;						//���I�I�u�W�F�N�g(�����郂�f���j

	CVector2 m_2DPosition = CVector2::Zero;					//2D�̃x�N�g��
	CVector3 m_3DPosition = CVector3::Zero;					//3D�̃x�N�g��
	CVector3 m_SpritePosition = { -640.0f,-360.0f,0.0f };		//3D�̃x�N�g��
	CQuaternion m_Rotation = CQuaternion::Identity;			//��]��
	CVector4 m_Color = CVector4::White;						//�F(���j
	CVector3 m_BoxScale = { 1.5f,8.0f,1.5f };				//���̑傫��
	CVector3 m_SphereScale = { 3.0f,3.0f,3.0f };			//���̑傫��
	CVector3 m_Scale = CVector3::One;						//�傫��
	CVector2 m_2DPivot = CVector2::Zero;					//2D�̊�_

	wchar_t testText[128] = {};								//������(Font�Ŏg���Ă���j
	int testtext = 0;										//%d�̕����ɓ��鐔��

	bool InitBox = false;									//true�ɂȂ�Ɣ����o��
	bool InitSphere = false;								//true�ɂȂ�Ƌ����o��
	bool InitSprite = false;								//true�ɂȂ�ƊG���o��
	bool InitFont = false;									//true�ɂȂ�ƕ������o��
	bool InitEfect = false;									//true�ɂȂ�ƃG�t�F�N�g���o��
	bool InitSky = false;									//true�ɂȂ�ƃL���[�u�}�b�v���o��
	bool InitSE = false;									//true�ɂȂ��SE���o��
	bool InitBGM = false;									//true�ɂȂ��BGM���o��
	bool InitPhysi = false;									//true�ɂȂ�ƐÓI�I�u�W�F�N�g�����f���ɓ��Ă͂܂�
	bool InitCharcon = false;								//true�ɂȂ�ƃL�����R�������f���ɓ��Ă͂܂�

private:
	int a = 0;												//�ق��̃N���X���猩��Ȃ��ϐ�
};