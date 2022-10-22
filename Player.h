#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "Input.h"
#include"ViewProjection.h"
#include "DebugText.h"
#include"Bullet.h"
#include<memory>
#include<list>

/// <summary>
/// 自キャラ
/// </summary>
class Player
{
public:
	/// <summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textuerHandle">テクスチャハンドル</param>
	void Initialize(Model* model, uint32_t textuerHandle,Model*model2);

	/// <summary>
	///更新
	/// </summary>
	void Update();

	/// <summary>
	///描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション(参照渡し)</param>
	void Draw(ViewProjection& viewProjection_);

	float Radius();

	Vector3 GetWorldPosition();

	void Attack();

	std::list<std::unique_ptr<Bullet>>bullet_;
	const std::list<std::unique_ptr<Bullet>>& GetBullets() { return bullets_; }

private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	// ワールド変換データ
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	Sprite* sprite_ = nullptr;

	// モデル
	Model* model_ = nullptr;
	Model* model2_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	int HeightFlag;
	int WidthFlag;

	float ReloadTime;

	bool TriggerFlag;

	float radius = 1.0f;

	std::list<std::unique_ptr<Bullet>> bullets_;
};