#pragma once
#include"Enemy.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"
#include "TextureManager.h"

class Enemy4:private Enemy
{
public:
	void EnemyInitialize(Model* model);
	void EnemyUpdate();
	//void EnemyMove();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
	void OnCollision();
	float Radius();

	Vector3 GetWorldPosition();
};
