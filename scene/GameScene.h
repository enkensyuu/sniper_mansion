﻿#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Enemy6.h"


/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
  /// <summary>
  /// コンストクラタ
  /// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	uint32_t textureHandle_ = 0u;


	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;

	Enemy* enemy_ = nullptr;
	Model* enemymodel = nullptr;


	Enemy2* enemy2_ = nullptr;
	Model* enemymodel2 = nullptr;

	Enemy3* enemy3_ = nullptr;
	Model* enemymodel3 = nullptr;

	Enemy4* enemy4_ = nullptr;
	Model* enemymodel4 = nullptr;

	Enemy5* enemy5_ = nullptr;
	Model* enemymodel5 = nullptr;

	Enemy6* enemy6_ = nullptr;
	Model* enemymodel6 = nullptr;

	WorldTransform worldTransform_;

	ViewProjection viewProjection_;

};
