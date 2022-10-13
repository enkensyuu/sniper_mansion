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
	WorldTransform worldTransformEnemy_;
	int Enemyflag_ = 0;
public:
	void EnemyInitialize(Model* model,uint32_t textureHandle);
	void EnemyUpdate();
	//void EnemyMove();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
};