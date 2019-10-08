#pragma once

#include "tkEngine/graphics/tkLight.h"
#include "tkEngine/light/tkLightBase.h"

namespace tkEngine {
	namespace prefab {
		/// <summary>
		/// �X�|�b�g���C�g�B
		/// </summary>
		class CSpotLight : public CLightBase {
		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			CSpotLight();
			/// <summary>
			/// �f�X�g���N�^�B
			/// </summary>
			~CSpotLight();
			/// <summary>
			/// �X�|�b�g���C�g�̃p�����[�^���X�V����B
			/// </summary>
			/// <param name="position">�X�|�b�g���C�g�̍��W</param>
			/// <param name="color">�X�|�b�g���C�g�̃J���[</param>
			/// <param name="direction">�Ǝ˕���</param>
			/// <param name="angle">�Ǝˊp�x</param>
			/// <param name="length">�Ǝˋ���</param>
			/// <param name="attnPow">
			/// �����W���B
			/// 1.0�Ȃ���`�̌����B1.0���傫�Ȑ��l��ݒ肷��ƁA����`�Ȍ����ɂȂ�܂��B
			/// </param>
			void UpdateParam(
				const CVector3& position, 
				const CVector3& color, 
				const CVector3& direction,
				float length,
				float attnPow = 1.0f
			);
		private:
			/// <summary>
			/// �X�V�J�n���ɌĂ΂�鏈���B
			/// </summary>
			/// <returns></returns>
			bool StartSub() override final;
			/// <summary>
			/// �X�V�����B
			/// </summary>
			void Update() override final;
		private:
			SSpotLight light;		//�X�|�b�g���C�g�B
		};
	}
}