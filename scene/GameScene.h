﻿#pragma once
#include "Audio.h"
#include "DebugText.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DirectXMath.h>
#include"DebugCamera.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include"Mansion.h"

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

	void OnCollision();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;

	Model* playermodel_ = nullptr;

	Mansion* mansion_ = nullptr;
	Model* DODAImodel_ = nullptr;
	Model* GARASUmodel_ = nullptr;
	Model* HASIRA_YUKAmodel_ = nullptr;
	Model* SOTO_WAKUmodel_ = nullptr;

	Sprite* sprite_ = nullptr;

	uint32_t textureHandle_ = 0u;

	Player* player_ = nullptr;

	Model* bulletmodel_ = nullptr;

	ViewProjection viewProjection_;

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

	// テクスチャハンドル
	uint32_t textureHandle1_ = 0;
	uint32_t textureHandle2_ = 0;
	uint32_t textureHandle3_ = 0;

	Sprite* sprite1_ = nullptr;
	Sprite* sprite2_ = nullptr;
	Sprite* sprite3_ = nullptr;
	int Ransuu;

	int timer = 600;
	int timer2 = 60;

	int scene = 0;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
