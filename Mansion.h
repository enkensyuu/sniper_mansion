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

class Mansion
{
public:
	/// <summary>
	///初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textuerHandle">テクスチャハンドル</param>
	void Initialize(Model* model, Model* model2, Model* model3, Model* model4);

	/// <summary>
	///更新
	/// </summary>
	void Update();

	/// <summary>
	///描画
	/// </summary>
	/// <param name="viewProjection">ビュープロジェクション(参照渡し)</param>
	void Draw(ViewProjection& viewProjection_);


private:
	Input* input_ = nullptr;
	DebugText* debugText_ = nullptr;

	Sprite* sprite_ = nullptr;

	// モデル
	Model* model_ = nullptr;
	Model* model2_ = nullptr;
	Model* model3_ = nullptr;
	Model* model4_ = nullptr;

	// ワールド変換データ
	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0u;
};