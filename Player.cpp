#include"Player.h"
#include <cassert>
#include"Procession.h"

void Player::Initialize(Model* model, Model* model2)
{
	// NULL�|�C���^�`�F�b�N
	assert(model);
	assert(model2);

	model_ = model;
	model2_ = model2;

	WidthFlag = 0;

	HeightFlag = 1;

	textureHandle_ = TextureManager::Load("sniper.png");
	sprite_ = Sprite::Create(textureHandle_, { 0,0 });

	// �V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	worldTransform_.Initialize();
}

void Player::Update()
{
	// �f�X�t���O�̗������e���폜
	bullets_.remove_if([](std::unique_ptr<Bullet>& bullet)
		{
			return bullet->IsDead();
		}
	);


	if (input_->IsOutPush(DIK_SPACE) && HeightFlag == 1)
	{
		HeightFlag = 0;
		WidthFlag = 1;
	}

	else if (input_->IsOutPush(DIK_SPACE) && WidthFlag == 1)
	{
		HeightFlag = 1;
		WidthFlag = 0;
		Attack();

	}

	// �e�X�V
	for (std::unique_ptr<Bullet>& bullet : bullets_)
	{
		bullet->Update();
	}
}

void Player::Draw(ViewProjection& viewProjection)
{
	//model_->Draw(worldTransform3DReticle_, viewProjection);
	// �e�`��
	for (std::unique_ptr<Bullet>& bullet : bullets_)
	{
		bullet->Draw(viewProjection);
	}
}

void Player::DrawUI()
{
	sprite_->Draw();
}

void Player::Attack()
{
	// �e�̑��x
	const float kBulletSpeed = 2.0f;
	Vector3 velocity(0, 0, kBulletSpeed);

	// �e�𐶐����A������
	std::unique_ptr < Bullet> newBullet = std::make_unique<Bullet>();
	newBullet->Initialize(model2_, worldTransform_.matWorld_, velocity);

	// �e��o�^����
	bullets_.push_back(std::move(newBullet));
}

Vector3 Player::GetWorldPosition()
{
	// ���[���h���W������ϐ�
	Vector3 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

float Player::Radius()
{
	return radius;
}