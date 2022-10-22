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
	// ����Ώ�A��B�̍��W
	Vector3 posA, posB;

	//���e���X�g�̎擾
	const std::list<std::unique_ptr<Bullet>>& playerBullets = player_->GetBullets();

	posA = enemy1_->GetWorldPosition();

	// ���L�����ƓG�e�S�Ă̓����蔻��
	for (const std::unique_ptr<Bullet>& bullet : playerBullets) {
		//�G�e�̍��W
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