#include "stdafx.h"
#include "test.h"

test::test()
{
}

test::~test()
{
	if (InitBox)														//��
	{
		DeleteGO(m_testBox);
	}
	if (InitSphere)														//��
	{
		DeleteGO(m_testSphere);
	}
	if (InitSprite)														//�G
	{
		DeleteGO(m_testSprite);
	}
	if (InitFont)														//����
	{
		DeleteGO(m_testFont);
	}
	if (InitEfect)														//�G�t�F�N�g
	{
		DeleteGO(m_testEfect);
	}
	if (InitSky)														//��
	{
		DeleteGO(m_testSky);
	}
	if (InitBGM)														//BGM
	{
		DeleteGO(m_testBGM);
	}
}

bool test::Start()
{
	if (InitBox)														//��
	{
		m_testBox = NewGO<prefab::CSkinModelRender>(0);
		m_testBox->Init(L"modelData/testBox.cmo");						//�����������f�����Ă�
		m_testBox->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testBox->SetScale(m_BoxScale);								//�傫�������߂�
		m_testBox->SetRotation(m_Rotation);								//��]�������߂�
	}
	if (InitSphere)														//��
	{
		m_testSphere = NewGO<prefab::CSkinModelRender>(0);
		m_testSphere->Init(L"modelData/testSphere.cmo");				//�����������f�����Ă�
		m_testSphere->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testSphere->SetScale(m_SphereScale);								//�傫�������߂�
		m_testSphere->SetRotation(m_Rotation);								//��]�������߂�
	}
	if (InitSprite)														//�G
	{
		m_testSprite = NewGO<prefab::CSpriteRender>(0);
		m_testSprite->Init(L"sprite/��test.dds", 1280.0f, 720.0f, false);//���������G���ĂԁB�����ɑ傫�������߂�Btrue�ɂ����3D��Ԃɕ\�������
		m_testSprite->SetPosition(m_SpritePosition);						//�ʒu�����߂�
		m_testSprite->SetScale(m_Scale);								//�傫�������߂�
		m_testSprite->SetRotation(m_Rotation);							//��]�������߂�
		m_testSprite->SetPivot(m_2DPivot);								//��_�����߂�
	}
	if (InitFont)														//����
	{
		m_testFont = NewGO<prefab::CFontRender>(0);
		swprintf_s(testText, L"%d", testtext);							//textText�ɕ�������͂���
		m_testFont->SetText(testText);									//����������������Ă�
		m_testFont->SetPosition(m_2DPosition);							//�ʒu�����߂�
		m_testFont->SetPivot(m_2DPivot);								//��_�����߂�
		m_testFont->SetColor(m_Color);									//�F�����߂�
		m_testFont->SetScale(1.0f);										//�傫�������߂�
		m_testFont->SetRotation(0.0f);									//��]�������߂�
	}
	if (InitEfect)														//�G�t�F�N�g
	{
		m_testEfect = NewGO<prefab::CEffect>(0);
		m_testEfect->Play(L"effect/test.efk");							//�o�������G�t�F�N�g���Ă�
		m_testEfect->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testEfect->SetScale(m_Scale);									//�傫�������߂�
		m_testEfect->SetRotation(m_Rotation);							//��]�������߂�
	}
	if (InitSky)														//��
	{
		m_testSky = NewGO<prefab::CSky>(0);
		m_testSky->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testSky->SetScale(m_Scale);									//�傫�������߂�
	}
	if (InitSE)															//SE
	{
		m_testSE = NewGO<prefab::CSoundSource >(0);
		m_testSE->Init(L"sound/coinGet.wav");							//�������Ă�
		m_testSE->SetPosition(m_3DPosition);							//�ʒu�����߂�B�Ȃ��Ă�����
		m_testSE->SetVolume(1.0f);										//����
		m_testSE->Play(false);											//�������[�v���邩�ǂ���
	}
	if (InitBGM)														//BGM
	{	
		m_testBGM = NewGO<prefab::CSoundSource>(0);
		m_testBGM->Init(L"sound/bgm.wav");								//�����������f�����Ă�
		m_testBGM->SetPosition(m_3DPosition);							//�ʒu�����߂�B�Ȃ��Ă�����
		m_testBGM->SetVolume(1.0f);										//����
		m_testBGM->Play(true);											//�������[�v���邩�ǂ���
	}	
	if (InitPhysi)														//�ÓI�I�u�W�F�N�g
	{
		m_testPhysics.SetPositionAndRotation(m_3DPosition, m_Rotation);	//�ÓI�I�u�W�F�N�g���ł���(�����j
	}
	if (InitCharcon)													//�L�����R��
	{
		m_Characon.Init(20.0f, 100.0f, m_3DPosition);					//�L�����R�����ł���(�����j
	}
	return true;
}

void test::Update()
{
	CVector3 m_MoveSpeed = CVector3::Zero;
	if (InitCharcon)													//�L�����R��
	{
		m_3DPosition = m_Characon.Execute(m_MoveSpeed);					//�L�����R�����ړ�����(�����j
	}

	if (InitBGM)														//BGM
	{
		m_testBGM->SetPosition(m_3DPosition);							//�ʒu�����߂�B
		m_testBGM->SetVolume(1.0f);										//����
	}

	if (InitSky)														//��
	{
		m_testSky->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testSky->SetScale(m_Scale);									//�傫�������߂�
	}

	if (InitEfect)														//�G�t�F�N�g
	{
		m_testEfect->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testEfect->SetScale(m_Scale);									//�傫�������߂�
		m_testEfect->SetRotation(m_Rotation);							//��]�������߂�
	}

	if (InitFont)														//����
	{
		swprintf_s(testText, L"%d", testtext);							//textText�ɕ�������͂���
		m_testFont->SetText(testText);									//����������������Ă�
		m_testFont->SetPosition(m_2DPosition);							//�ʒu�����߂�
		m_testFont->SetPivot(m_2DPivot);								//��_�����߂�
		m_testFont->SetColor(m_Color);									//�F�����߂�
		m_testFont->SetScale(1.0f);										//�傫�������߂�
		m_testFont->SetRotation(0.0f);									//��]�������߂�
	}

	if (InitSprite)														//�G
	{
		m_testSprite->SetPosition(m_SpritePosition);
		m_testSprite->SetScale(m_Scale);								//�傫�������߂�
		m_testSprite->SetRotation(m_Rotation);							//��]�������߂�
		m_testSprite->SetPivot(m_2DPivot);								//��_�����߂�
	}

	if (InitSphere)														//��
	{
		m_testSphere->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testSphere->SetScale(m_SphereScale);									//�傫�������߂�	
		m_testSphere->SetRotation(m_Rotation);								//��]�������߂�
	}

	if (InitBox)														//��
	{
		m_testBox->SetPosition(m_3DPosition);							//�ʒu�����߂�
		m_testBox->SetScale(m_BoxScale);									//�傫�������߂�
		m_testBox->SetRotation(m_Rotation);								//��]�������߂�
	}
}