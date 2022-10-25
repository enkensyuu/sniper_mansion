#include "Mansion.h"
#include<cassert>
#include"Procession.h"

void Mansion::Initialize(Model* model)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	// シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	worldTransform_.Initialize();

	worldTransform_.scale_ = { 30,30,30 };

	worldTransform_.rotation_ = { 0,1.55f, 0};

	worldTransform_.translation_ = { 0,-70,150 };

	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
}

void Mansion::Update()
{
}

void Mansion::Draw(ViewProjection& viewProjection_)
{
	model_->Draw(worldTransform_, viewProjection_);
}
