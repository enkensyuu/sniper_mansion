#include"Enemy5.h"
#include "Audio.h"
#include<cassert>
#include"Procession.h"

void Enemy5::EnemyInitialize(Model* model)
{
	assert(model);

	model_ = model;

	//worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};

	worldTransform_.Initialize();
	worldTransform_.translation_ = { 10,0,0 };

	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
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

	model_->Draw(worldTransform_, viewProjection);
}

void Enemy5::OnCollision()
{
	
}

float Enemy5::Radius()
{
	return radius;
}

Vector3 Enemy5::GetWorldPosition()
{
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}