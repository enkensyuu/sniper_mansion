#include "Player.h"
#include<cassert>
#include"Procession.h"

void Player::Initialize(Model* model, uint32_t textuerHandle)
{
	assert(model);

	model_ = model;

	textureHandle_ = textuerHandle;

	HeightFlag = 1;

	WidthFlag = 0;

	// �V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	worldTransform_.Initialize();

}

void Player::Update()
{
	Vector3 move = { 0,0,0 };

	const float speed = 2.0f;

	if (input_->PushKey(DIK_SPACE))
	{
		if (HeightFlag == 1)
		{
			move.y += speed;
		}
		else if (WidthFlag == 1)
		{
			move.x += speed;
		}
	}


	if (input_->IsOutPush(DIK_SPACE) && HeightFlag == 1)
	{
		HeightFlag = 0;
		WidthFlag = 1;
	}

	else if (input_->IsOutPush(DIK_SPACE) && WidthFlag == 1)
	{
		HeightFlag = 1;
		WidthFlag = 0;
	}

	//�@���W�ړ�(�x�N�g���̉��Z)
	worldTransform_.translation_ += move;

	// �ړ����E���W
	const float kMoveLimitX = 35;
	const float kMoveLimitY = 19;

	//// �͈͂𒴂��Ȃ�����
	//worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	//worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	//worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	//worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	// �s��X�V
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
	debugText_->SetPos(50, 50);
	debugText_->Printf("Height:%d", HeightFlag);
	debugText_->SetPos(50, 100);
	debugText_->Printf("Width:%d", WidthFlag);
}

void Player::Draw(ViewProjection& viewProjection_)
{
	model_->Draw(worldTransform_, viewProjection_, textureHandle_);
}

Vector2 Player::GetWorldPosition()
{
	// ���[���h���W������ϐ�
	Vector2 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;

	return worldPos;
}
