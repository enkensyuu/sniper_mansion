#include"Enemy.h"
#include "Audio.h"
#include<cassert>
#include<stdlib.h>
#include<time.h>
#include"Procession.h"

void Enemy::EnemyInitialize(Model* model, int ransuu)
{
	assert(model);

	model_ = model;
	input_ = Input::GetInstance();
	debugText = DebugText::GetInstance();
	worldTransform_.Initialize();

	isDead_ = 1;

	worldTransform_.translation_ = { 0.5f,-12,10 };
	
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Enemy::EnemyUpdate()
{
	time--;
	Vector3 move = { 0,0,0 };

	float speed = 0.1f;

	// 移動限界座標
	const float kMoveLimitX = 35;
	const float kMoveLimitY = 19;

	// 範囲を超えない処理
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

	if (time<0)
	{
		worldTransform_.translation_ = { 0.5f,-12,10 };
		time = 360;
	}

	// 行列更新
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
	debugText->SetPos(50, 50);
	debugText->Printf("reset:%d", time);
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

	model_->Draw(worldTransform_, viewProjection);
}

void Enemy::OnCollision()
{
	isDead_ = 0;
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

