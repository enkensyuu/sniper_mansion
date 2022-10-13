#include"Enemy.h"
#include "Audio.h"
#include<cassert>

void Enemy::EnemyInitialize(Model* model, uint32_t textureHandle)
{
	assert(model);

	model_ = model;
	
	textureHandleEnemy_ = textureHandle;
	textureHandleEnemy_ = TextureManager::Load("Enemy.png");
	
	//worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy_.Initialize();
}

void Enemy::EnemyUpdate()
{
	//worldTransformEnemy_.TransferMatrix();
}

void Enemy::EnemyBorn()
{
	if (Enemyflag_ == 0)
	{
		Enemyflag_ = 1;
	}
}

void Enemy::EnemyDraw(ViewProjection& viewProjection)
{
	
	model_->Draw(worldTransformEnemy_, viewProjection, textureHandleEnemy_);
}
