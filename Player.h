#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "Input.h"
#include"ViewProjection.h"
#include "DebugText.h"
#include"Bullet.h"
#include<memory>
#include<list>

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
	void Initialize(Model* model, uint32_t textuerHandle,Model*model2);

	/// <summary>
	///�X�V
	/// </summary>
	void Update();

	/// <summary>
	///�`��
	/// </summary>
	/// <param name="viewProjection">�r���[�v���W�F�N�V����(�Q�Ɠn��)</param>
	void Draw(ViewProjection& viewProjection_);

	float Radius();

	Vector3 GetWorldPosition();

	void Attack();

	std::list<std::unique_ptr<Bullet>>bullet_;
	const std::list<std::unique_ptr<Bullet>>& GetBullets() { return bullets_; }

private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	// ���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	Sprite* sprite_ = nullptr;

	// ���f��
	Model* model_ = nullptr;
	Model* model2_ = nullptr;

	// �e�N�X�`���n���h��
	uint32_t textureHandle_ = 0u;

	int HeightFlag;
	int WidthFlag;

	float ReloadTime;

	bool TriggerFlag;

	float radius = 1.0f;

	std::list<std::unique_ptr<Bullet>> bullets_;
};