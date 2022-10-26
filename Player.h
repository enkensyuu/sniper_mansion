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
	void Initialize(Model* model,Model*model2);



	/// <summary>
	///�X�V
	/// </summary>
	void Update();

	/// <summary>
	///�`��
	/// </summary>
	/// <param name="viewProjection">�r���[�v���W�F�N�V����(�Q�Ɠn��)</param>
	void Draw(ViewProjection& viewProjection_);

	void DrawUI();

	float Radius();

	Vector3 GetWorldPosition();

	Vector3 ReticlePosition();

	void Attack();

	std::list<std::unique_ptr<Bullet>>bullet_;
	const std::list<std::unique_ptr<Bullet>>& GetBullets() { return bullets_; }

	std::unique_ptr<Sprite> sprite2DReticle_;
private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	Sprite* sprite_ = nullptr;

	// ���f��
	Model* model_ = nullptr;
	Model* model2_ = nullptr;

	// ���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	WorldTransform worldTransform3DReticle_;

	ViewProjection viewProjection_;

	// �e�N�X�`���n���h��
	uint32_t textureReticle= 0u;

	int HeightFlag;
	int WidthFlag;

	float ReloadTime;

	bool TriggerFlag;

	float radius = 1.0f;

	std::list<std::unique_ptr<Bullet>> bullets_;
};