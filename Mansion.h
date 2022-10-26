#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Mansion
{
public:
	/// <summary>
	///������
	/// </summary>
	/// <param name="model">���f��</param>
	/// <param name="textuerHandle">�e�N�X�`���n���h��</param>
	void Initialize(Model* model, Model* model2, Model* model3, Model* model4);

	/// <summary>
	///�X�V
	/// </summary>
	void Update();

	/// <summary>
	///�`��
	/// </summary>
	/// <param name="viewProjection">�r���[�v���W�F�N�V����(�Q�Ɠn��)</param>
	void Draw(ViewProjection& viewProjection_);


private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	Sprite* sprite_ = nullptr;

	// ���f��
	Model* model_ = nullptr;
	Model* model2_ = nullptr;
	Model* model3_ = nullptr;
	Model* model4_ = nullptr;

	// ���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	// �e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;
};