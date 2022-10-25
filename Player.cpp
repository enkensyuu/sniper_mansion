#include"Player.h"
#include <cassert>
#include"Procession.h"

void Player::Initialize(Model * model,Model * model2)
{
	// NULL�|�C���^�`�F�b�N
	assert(model);
	assert(model2);

	model_ = model;
	model2_ = model2;

	WidthFlag = 0;

	HeightFlag = 1;

	// �V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	playertextureHandle_ = TextureManager::Load("sniper.png");

	sprite_ = Sprite::Create(playertextureHandle_, { 0,0 });

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


	Vector3 move = { 0,0,0 };

	const float speed = 2.0f;

	if (input_->PushKey(DIK_SPACE))
	{
		if (HeightFlag == 1)
		{
			move.y += speed;
		}
		else if (WidthFlag == 1)
		{
			move.x += speed;
		}
	}


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

	//�@���W�ړ�(�x�N�g���̉��Z)
	worldTransform_.translation_ += move;

	Vector2 position = sprite_->GetPosition();

	position.x += move.x;
	position.y += move.y;

	sprite_->SetPosition(position);

	// �ړ����E���W
	const float kMoveLimitX = 35;
	const float kMoveLimitY = 19;

	// �͈͂𒴂��Ȃ�����
	//worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	//worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	//worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	//worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	// �s��X�V
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();
	debugText_->SetPos(50, 50);
	debugText_->Printf("Height:%d", HeightFlag);
	debugText_->SetPos(50, 100);
	debugText_->Printf("Width:%d", WidthFlag);

	// �e�X�V
	for (std::unique_ptr<Bullet>& bullet : bullets_)
	{
		bullet->Update();
	}
}

void Player::ModelDraw(ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection);
	// �e�`��
	for (std::unique_ptr<Bullet>& bullet : bullets_)
	{
		bullet->Draw(viewProjection);
	}
}

void Player::SpriteDraw()
{
	sprite_->Draw();
}

void Player::Attack()
{
		// �e�̑��x
		const float kBulletSpeed = 2.0f;
		Vector3 velocity(0, 0, kBulletSpeed);

		// ���x�x�N�g�������@�̌����ɍ��킹�ĉ�]������
		velocity = Mat_Velocity(velocity, worldTransform_.matWorld_);

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