#include"Enemy3.h"
#include "Audio.h"
#include<cassert>
#include"Procession.h"
#include<stdlib.h>
#include<time.h>

void Enemy3::EnemyInitialize(Model* model, int ransuu)
{
	assert(model);

	model_ = model;
	input_ = Input::GetInstance();
	worldTransform_.Initialize();

	isDead_ = 1;

	worldTransform_.translation_ = { 7,-4.5f,10 };
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Enemy3::EnemyUpdate()
{
	time--;
	Vector3 move = { 0,0,0 };

	float speed = 0.1f;

	// �ړ����E���W
	const float kMoveLimitX = 35;
	const float kMoveLimitY = 19;

	// �͈͂𒴂��Ȃ�����
	/*worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);*/


	if (input_->PushKey(DIK_SPACE))
	{
		if (HeightFlag == 1)
		{
			move.y += speed;
		}
		else if (WidthFlag == 1)
		{
			move.x -= speed;
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
	worldTransform_.translation_ += move;

	if (time < 0)
	{
		worldTransform_.translation_ = { 7,-4.5f,10 };
		time = 360;
	}
	// �s��X�V
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Enemy3::EnemyBorn()
{
	if (Enemyflag_ == 0)
	{
		Enemyflag_ = 1;
	}
}

void Enemy3::EnemyDraw(ViewProjection& viewProjection)
{

	model_->Draw(worldTransform_, viewProjection);
}

void Enemy3::OnCollision()
{
	isDead_ = 0;
}

float Enemy3::Radius()
{
	return radius;
}

Vector3 Enemy3::GetWorldPosition()
{
	// ���[���h���W������ϐ�
	Vector3 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

