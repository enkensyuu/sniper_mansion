#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete playermodel_;
	delete bulletmodel_;
	delete sprite_;
	delete player_;
	delete enemymodel;
	delete enemy_;
	delete enemymodel2;
	delete enemymodel3;
	delete enemymodel4;
	delete enemymodel5;
	delete enemymodel6;
	delete enemy2_;
	delete enemy3_;
	delete enemy4_;
	delete enemy5_;
	delete enemy6_;
	delete mansion_;
	delete mansionmodel_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	playermodel_ = Model::Create();

	bulletmodel_ = Model::Create();

	enemymodel = Model::Create();
	enemymodel2 = Model::Create();
	enemymodel3 = Model::Create();
	enemymodel4 = Model::Create();
	enemymodel5 = Model::Create();
	enemymodel6 = Model::Create();

	mansionmodel_ = Model::CreateFromOBJ("Builbing", true);
	

	viewProjection_.Initialize();
	player_ = new Player();
	player_->Initialize(playermodel_, bulletmodel_);

	mansion_ = new Mansion();
	mansion_->Initialize(mansionmodel_);

#pragma region Enemy

	enemy_ = new Enemy();
	enemy_->EnemyInitialize(enemymodel, textureHandle_, Ransuu);

	enemy2_ = new Enemy2();
	enemy2_->EnemyInitialize(enemymodel2, textureHandle_);

	enemy3_ = new Enemy3();
	enemy3_->EnemyInitialize(enemymodel3, textureHandle_);

	enemy4_ = new Enemy4();
	enemy4_->EnemyInitialize(enemymodel4, textureHandle_);

	enemy5_ = new Enemy5();
	enemy5_->EnemyInitialize(enemymodel5, textureHandle_);

	enemy6_ = new Enemy6();
	enemy6_->EnemyInitialize(enemymodel6, textureHandle_);
#pragma endregion

}

void GameScene::Update() {
	player_->Update();
	enemy_->EnemyUpdate();
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	//player_->SpriteDraw();
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//player_->ModelDraw(viewProjection_);
	enemy_->EnemyDraw(viewProjection_);
	enemy2_->EnemyDraw(viewProjection_);
	enemy3_->EnemyDraw(viewProjection_);
	enemy4_->EnemyDraw(viewProjection_);
	enemy5_->EnemyDraw(viewProjection_);
	enemy6_->EnemyDraw(viewProjection_);
	mansion_->Draw(viewProjection_);
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
