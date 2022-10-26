#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Model.h"
#include "TextureManager.h"
#include"Input.h"
#include "DebugText.h"

class Enemy
{
protected:
	int Enemyflag_ = 0;
	float radius = 1.0f;
	Input* input_ = nullptr;
	DebugText* debugText = nullptr;
	Model* model_ = nullptr;
	WorldTransform worldTransform_;
	int isDead_=1;
	int HeightFlag = 1;
	int WidthFlag = 1;
	int time = 360;
public:
	void EnemyInitialize(Model* model, int ransuu);
	void EnemyUpdate();
	void EnemyBorn();
	void EnemyDraw(ViewProjection& viewProjection);
	void OnCollision();
	float Radius();
	int IsDead() const { return isDead_; }

	Vector3 GetWorldPosition();
};