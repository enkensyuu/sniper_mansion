#include "Mansion.h"
#include<cassert>
#include"Procession.h"

void Mansion::Initialize(Model* model, Model* model2, Model* model3, Model* model4)
{
	// NULLポインタチェック
	assert(model);
	assert(model2);
	assert(model3);
	assert(model4);

	model_ = model;
	model2_ = model2;
	model3_ = model3;
	model4_ = model4;

	// シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	worldTransform_.Initialize();

	worldTransform_.scale_ = { 5,5,5 };

	worldTransform_.rotation_ = { 0,1.55f, 0};

	worldTransform_.translation_ = { 7,-25,10 };

	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Mansion::Update()
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

	if (time < 0)
	{
		worldTransform_.translation_ = { 7,-25,10 };
		time = 360;
	}
	// 行列更新
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Mansion::Draw(ViewProjection& viewProjection_)
{
	model_->Draw(worldTransform_, viewProjection_);
	model2_->Draw(worldTransform_, viewProjection_);
	model3_->Draw(worldTransform_, viewProjection_);
	model4_->Draw(worldTransform_, viewProjection_);
}
