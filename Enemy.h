#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"
#include "TextureManager.h"

class Enemy
{
protected:
	uint32_t textureHandleEnemy_ = 0u;
	Model* model_ = nullptr;
	WorldTransform worldTransform_;
	int Enemyflag_ = 0;
	float radius = 1.0f;
	int LiveFlag = 1;
public:
	void EnemyInitialize(Model* model, uint32_t textureHandle);
	void EnemyUpdate();
	//void EnemyMove();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
	void OnCollision();
	float Radius();

	Vector3 GetWorldPosition();

	int Live() { return LiveFlag; }
};