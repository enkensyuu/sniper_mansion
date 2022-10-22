#include"GameSystem.h"
#include"Procession.h"

void GameSystem::Initialize()
{

}

void GameSystem::Update()
{

}

void GameSystem::Draw()
{

}

void GameSystem::CheckAllCollision()
{
	// 判定対象AとBの座標
	Vector3 posA, posB;

	//自弾リストの取得
	const std::list<std::unique_ptr<Bullet>>& playerBullets = player_->GetBullets();

	posA = enemy1_->GetWorldPosition();

	// 自キャラと敵弾全ての当たり判定
	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//敵弾の座標
		posB = bullet->GetWorldPosition();
		Vector3 len = Vectornorm(posA, posB);
		float dis = Length(len);
		float radius = enemy1_->Radius() + bullet->Radius();
		if (dis <= radius)
		{
			enemy1_->OnCollision();
			bullet->OnCollision();
		}
	}
}