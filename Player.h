#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
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
	void Initialize(Model* model,Model*model2);

	/// <summary>
	///更新
	/// </summary>
	void Update();

	/// <summary>
	///描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション(参照渡し)</param>
	void ModelDraw(ViewProjection& viewProjection_);

	void SpriteDraw();

	float Radius();

	Vector3 GetWorldPosition();

	void Attack();

	std::list<std::unique_ptr<Bullet>>bullet_;
	const std::list<std::unique_ptr<Bullet>>& GetBullets() { return bullets_; }


private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	Sprite* sprite_ = nullptr;

	// モデル
	Model* model_ = nullptr;
	Model* model2_ = nullptr;

	// ワールド変換データ
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	uint32_t playertextureHandle_ = 0u;

	int HeightFlag;
	int WidthFlag;

	float ReloadTime;

	bool TriggerFlag;

	float radius = 1.0f;

	std::list<std::unique_ptr<Bullet>> bullets_;
};