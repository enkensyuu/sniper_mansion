#pragma once
#include"Enemy.h"
#include "Audio.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"
#include "TextureManager.h"

class Enemy3 :private Enemy
{
public:
	void EnemyInitialize(Model* model, uint32_t textureHandle);
	void EnemyUpdate();
	//void EnemyMove();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
};
