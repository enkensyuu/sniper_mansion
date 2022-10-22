#include"Bullet.h"
#include <cassert>
#include"Procession.h"

void Bullet::Initialize(Model* model, const Matrix4& position, const Vector3& velocity)
{
	// NULL�|�C���^�`�F�b�N
	assert(model);

	model_ = model;

	textureHandle_ = TextureManager::Load("sniper.png");

	// �����Ŏ󂯎�������x�������o�ϐ��ɑ��
	velocity_ = velocity;

	worldTransform_.Initialize();

	// �����Ŏ󂯎�����������W���Z�b�g
	worldTransform_.translation_.x = position.m[3][0];
	worldTransform_.translation_.y = position.m[3][1];
	worldTransform_.translation_.z = position.m[3][2];
}

void Bullet::Update()
{
	worldTransform_.matWorld_ = Mat_Identity();
	worldTransform_.matWorld_ = MatWorld(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	// ���W���ړ�������(1�t���[�����̈ړ��ʂ𑫂�����)
	worldTransform_.translation_ += velocity_;

	worldTransform_.TransferMatrix();

	// ���Ԍo�߂Ńf�X
	if (--deathTimer_ <= 0)
	{
		isDead_ = true;
	}
}

void Bullet::Draw(const ViewProjection& viewProjection)
{
	// ���f���̕`��
	model_->Draw(worldTransform_, viewProjection,textureHandle_);
}

Vector3 Bullet::GetWorldPosition()
{
	// ���[���h���W������ϐ�
	Vector3 worldPos;
	// ���[���h�s��̕��s�ړ��������擾(���[���h���W)
	worldPos.x = worldTransform_.translation_.x;
	worldPos.y = worldTransform_.translation_.y;
	worldPos.z = worldTransform_.translation_.z;

	return worldPos;
}

void Bullet::OnCollision()
{
	isDead_ = true;
}

float Bullet::Radius()
{
	return radius_;
}