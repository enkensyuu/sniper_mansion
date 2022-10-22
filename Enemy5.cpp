#include"Enemy5.h"
#include "Audio.h"
#include<cassert>

void Enemy5::EnemyInitialize(Model* model, uint32_t textureHandle)
{
	assert(model);

	model_ = model;

	textureHandleEnemy_ = textureHandle;
	textureHandleEnemy_ = TextureManager::Load("Enemy.png");

	//worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};

	worldTransform_.Initialize();
	//worldTransformEnemy_.translation_ = { 100,10,10 };
}

void Enemy5::EnemyUpdate()
{
	//worldTransformEnemy_.TransferMatrix();
}

void Enemy5::EnemyBorn()
{
	if (Enemyflag_ == 0)
	{
		Enemyflag_ = 1;
	}
}

void Enemy5::EnemyDraw(ViewProjection& viewProjection)
{

	model_->Draw(worldTransform_, viewProjection, textureHandleEnemy_);
}

void Enemy5::OnCollision()
{
	LiveFlag = 0;
}

float Enemy5::Radius()
{
	return radius;
}

Vector3 Enemy5::GetWorldPosition()
{
	// ���[���h���W������ϐ�
	Vector3 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}