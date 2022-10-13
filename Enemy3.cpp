#include"Enemy3.h"
#include "Audio.h"
#include<cassert>

void Enemy3::EnemyInitialize(Model* model, uint32_t textureHandle)
{
	assert(model);

	model_ = model;

	textureHandleEnemy_ = textureHandle;
	textureHandleEnemy_ = TextureManager::Load("Enemy.png");

	//worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};

	worldTransformEnemy_.Initialize();
	//worldTransformEnemy_.translation_ = { 100,10,10 };
}

void Enemy3::EnemyUpdate()
{
	//worldTransformEnemy_.TransferMatrix();
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

	model_->Draw(worldTransformEnemy_, viewProjection, textureHandleEnemy_);
}