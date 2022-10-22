#include"Bullet.h"
#include <cassert>
#include"Procession.h"

void Bullet::Initialize(Model* model, const Matrix4& position, const Vector3& velocity)
{
	// NULLポインタチェック
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("sniper.png");

	// 引数で受け取った速度をメンバ変数に代入
	velocity_ = velocity;

	worldTransform_.Initialize();

	// 引数で受け取った初期座標をセット
	worldTransform_.translation_.x = position.m[3][0];
	worldTransform_.translation_.y = position.m[3][1];
	worldTransform_.translation_.z = position.m[3][2];
}

void Bullet::Update()
{
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	// 座標を移動させる(1フレーム分の移動量を足しこむ)
	worldTransform_.translation_ += velocity_;

	worldTransform_.TransferMatrix();

	// 時間経過でデス
	if (--deathTimer_ <= 0)
	{
		isDead_ = true;
	}
}

void Bullet::Draw(const ViewProjection& viewProjection)
{
	// モデルの描画
	model_->Draw(worldTransform_, viewProjection,textureHandle_);
}

Vector3 Bullet::GetWorldPosition()
{
	// ワールド座標を入れる変数
	Vector3 worldPos;
	// ワールド行列の平行移動成分を取得(ワールド座標)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

void Bullet::OnCollision()
{
	isDead_ = true;
}

float Bullet::Radius()
{
	return radius_;
}