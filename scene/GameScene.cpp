#include "GameScene.h"
#include "AxisIndicator.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include <cassert>
#include"Procession.h"

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
	delete enemy2_;
	delete enemy3_;
	delete enemy4_;
	delete enemy5_;
	delete mansion_;
	delete DODAImodel_;
	delete GARASUmodel_;
	delete	HASIRA_YUKAmodel_;
	delete SOTO_WAKUmodel_;
}

void GameScene::OnCollision()
{
	// 判定対象AとBの座標
	Vector3 posA, posB;

	//自弾リストの取得
	const std::list<std::unique_ptr<Bullet>>& playerBullets = player_->GetBullets();

#pragma region 敵1

	posA = enemy_->GetWorldPosition();

	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy_->OnCollision();
			bullet->OnCollision();
		}
	}

#pragma endregion

#pragma region 敵2
	posA = enemy2_->GetWorldPosition();

	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy2_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy2_->OnCollision();
			bullet->OnCollision();
		}
	}
#pragma endregion

#pragma region 敵3

	posA = enemy3_->GetWorldPosition();

	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy3_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy3_->OnCollision();
			bullet->OnCollision();
		}
	}

#pragma endregion

#pragma region 敵4

	posA = enemy4_->GetWorldPosition();

	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy4_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy4_->OnCollision();
			bullet->OnCollision();
		}
	}

#pragma endregion

#pragma region 敵5

	posA = enemy5_->GetWorldPosition();

	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy5_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy5_->OnCollision();
			bullet->OnCollision();
		}
	}

#pragma endregion

}


void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	Ransuu = 1;

	playermodel_ = Model::Create();

	bulletmodel_ = Model::CreateFromOBJ("Bullet", true);

	enemymodel = Model::CreateFromOBJ("TargetRed", true);
	enemymodel2 = Model::CreateFromOBJ("TargetBlue", true);
	enemymodel3 = Model::CreateFromOBJ("TargetYellow", true);
	enemymodel4 = Model::CreateFromOBJ("Targetsky", true);
	enemymodel5 = Model::CreateFromOBJ("TargetPurple", true);

	DODAImodel_ = Model::CreateFromOBJ("DODAI", true);
	GARASUmodel_ = Model::CreateFromOBJ("GARASU", true);
	HASIRA_YUKAmodel_ = Model::CreateFromOBJ("HASIRA_YUKA", true);
	SOTO_WAKUmodel_ = Model::CreateFromOBJ("SOTO_WAKU", true);

	textureHandle1_ = TextureManager::Load("title.jpg");
	textureHandle2_ = TextureManager::Load("ru-ru.jpg");
	textureHandle3_ = TextureManager::Load("ED2.png");

	sprite1_ = Sprite::Create(textureHandle1_, { 0,0 });
	sprite2_ = Sprite::Create(textureHandle2_, { 0,0 });
	sprite3_ = Sprite::Create(textureHandle3_, { 0,0 });

	timer = 600;
	timer2 = 60;
	viewProjection_.Initialize();
	player_ = new Player();
	player_->Initialize(playermodel_, bulletmodel_);

	mansion_ = new Mansion();
	mansion_->Initialize(DODAImodel_, GARASUmodel_, HASIRA_YUKAmodel_, SOTO_WAKUmodel_);

#pragma region Enemy
	enemy_ = new Enemy();
	enemy_->EnemyInitialize(enemymodel, Ransuu);
	enemy2_ = new Enemy2();
	enemy2_->EnemyInitialize(enemymodel2, Ransuu);

	enemy3_ = new Enemy3();
	enemy3_->EnemyInitialize(enemymodel3, Ransuu);

	enemy4_ = new Enemy4();
	enemy4_->EnemyInitialize(enemymodel4, Ransuu);

	enemy5_ = new Enemy5();
	enemy5_->EnemyInitialize(enemymodel5, Ransuu);
#pragma endregion

	Ransuu = 0;
}

void GameScene::Update() {
	switch (scene)
	{
	case 0:
		Initialize();
		if (input_->TriggerKey(DIK_SPACE))
		{
			scene = 1;
		}
		break;
	case 1:
		timer2--;
		if (input_->TriggerKey(DIK_SPACE) && timer2 < 0)
		{
			scene = 2;
		}
		break;
	case  2:
		timer--;
		debugText_->SetPos(50, 50);
		debugText_->Printf("timer:%d", timer);
		if (timer < 0)
		{
			scene = 3;
		}
		break;
	case 3:
		if (enemy_->IsDead() == 0 && enemy2_->IsDead() == 0 && enemy3_->IsDead() == 0 && enemy4_->IsDead() == 0 && enemy5_->IsDead() == 0)
		{
			scene = 4;
			timer = 60;
		}
		viewProjection_.eye = { 0,0,-4.0f };

		viewProjection_.Initialize();
		player_->Update();
		enemy_->EnemyUpdate();
		enemy2_->EnemyUpdate();
		enemy3_->EnemyUpdate();
		enemy4_->EnemyUpdate();
		enemy5_->EnemyUpdate();
		mansion_->Update();
		OnCollision();
		break;
	case 4:
		if (input_->TriggerKey(DIK_SPACE))
		{
			scene = 0;
		}
		break;
	}
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
	switch (scene)
	{
	case 0:
		sprite1_->Draw();
		break;
	case 1:
		sprite2_->Draw();
		break;
	case 4:
		sprite3_->Draw();
		break;
	}
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
	switch (scene)
	{
	case 2:
		mansion_->Draw(viewProjection_);
		if (enemy_->IsDead() == 1)
		{
			enemy_->EnemyDraw(viewProjection_);
		}
		if (enemy2_->IsDead() == 1)
		{
			enemy2_->EnemyDraw(viewProjection_);
		}
		if (enemy3_->IsDead() == 1)
		{
			enemy3_->EnemyDraw(viewProjection_);
		}
		if (enemy4_->IsDead() == 1)
		{
			enemy4_->EnemyDraw(viewProjection_);
		}
		if (enemy5_->IsDead() == 1)
		{
			enemy5_->EnemyDraw(viewProjection_);
		}
		break;
	case 3:
		player_->Draw(viewProjection_);
		mansion_->Draw(viewProjection_);
		if (enemy_->IsDead() == 1)
		{
			enemy_->EnemyDraw(viewProjection_);
		}
		if (enemy2_->IsDead() == 1)
		{
			enemy2_->EnemyDraw(viewProjection_);
		}
		if (enemy3_->IsDead() == 1)
		{
			enemy3_->EnemyDraw(viewProjection_);
		}
		if (enemy4_->IsDead() == 1)
		{
			enemy4_->EnemyDraw(viewProjection_);
		}
		if (enemy5_->IsDead() == 1)
		{
			enemy5_->EnemyDraw(viewProjection_);
		}
		break;
	}
	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	switch (scene)
	{
	case 3:
		player_->DrawUI();
		break;
	}

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

