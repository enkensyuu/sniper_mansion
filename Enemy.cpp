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
	worldTransform_.Initialize();
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
	
	model_->Draw(worldTransform_, viewProjection, textureHandleEnemy_);
}

void Enemy::OnCollision()
{
	LiveFlag = 0;
}

float Enemy::Radius()
{
	return radius;
}

Vector3 Enemy::GetWorldPosition()
{
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

