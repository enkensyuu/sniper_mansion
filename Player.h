#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "Input.h"
#include"ViewProjection.h"
#include "DebugText.h"

/// <summary>
/// ���L����
/// </summary>
class Player
{
public:
	/// <summary>
	///������
	/// </summary>
	/// <param name="model">���f��</param>
	/// <param name="textuerHandle">�e�N�X�`���n���h��</param>
	void Initialize(Model* model, uint32_t textuerHandle);

	/// <summary>
	///�X�V
	/// </summary>
	void Update();

	/// <summary>
	///�`��
	/// </summary>
	/// <param name="viewProjection">�r���[�v���W�F�N�V����(�Q�Ɠn��)</param>
	void Draw(ViewProjection& viewProjection_);

	Vector2 GetWorldPosition();

private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	// ���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	Sprite* sprite_ = nullptr;

	// ���f��
	Model* model_ = nullptr;

	// �e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;

	int HeightFlag;
	int WidthFlag;
};