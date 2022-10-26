#pragma once
#include "DebugText.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h";
#include "Enemy.h";
#include "Enemy2.h";
#include "Enemy3.h";
#include "Enemy4.h";
#include "Enemy5.h";

class GameSystem
{
public:
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

	/// <summary>
	/// 衝突判定と応答
	/// </summary>
	void CheckAllCollision();

private:
	DebugText* debugText_ = nullptr;

	// 自キャラ
	Player* player_ = nullptr;

	// 敵キャラ
	Enemy* enemy1_ = nullptr;
	Enemy2* enemy2_ = nullptr;
	Enemy3* enemy3_ = nullptr;
	Enemy4* enemy4_ = nullptr;
	Enemy5* enemy5_ = nullptr;

};
