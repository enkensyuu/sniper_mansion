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
	int Enemyflag_ = 0;
	float radius = 1.0f;
	Model* model_ = nullptr;
	WorldTransform worldTransform_;

public:
	void EnemyInitialize(Model* model, bool ransuu);
	void EnemyUpdate();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
	void OnCollision();
	float Radius();

	Vector3 GetWorldPosition();
};