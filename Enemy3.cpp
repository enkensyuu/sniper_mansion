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

	worldTransform_.Initialize();
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

	model_->Draw(worldTransform_, viewProjection, textureHandleEnemy_);
}

void Enemy3::OnCollision()
{
	LiveFlag = 0;
}

float Enemy3::Radius()
{
	return radius;
}

Vector3 Enemy3::GetWorldPosition()
{
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

