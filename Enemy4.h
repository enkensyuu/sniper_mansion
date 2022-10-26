#pragma once
#include"Enemy.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"
#include "TextureManager.h"
#include"Input.h"

class Enemy4:private Enemy
{
public:
	void EnemyInitialize(Model* model,int ransuu);
	void EnemyUpdate();
	//void EnemyMove();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
	void OnCollision();
	float Radius();
	int IsDead() const { return isDead_; }

	Vector3 GetWorldPosition();
};
