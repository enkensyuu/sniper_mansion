#pragma once
#include "DebugText.h"
#include "DirectXCommon.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h";
#include "Enemy.h";
#include "Enemy2.h";
#include "Enemy3.h";
#include "Enemy4.h";
#include "Enemy5.h";

class GameSystem
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �Փ˔���Ɖ���
	/// </summary>
	void CheckAllCollision();

private:
	DebugText* debugText_ = nullptr;

	// ���L����
	Player* player_ = nullptr;

	// �G�L����
	Enemy* enemy1_ = nullptr;
	Enemy2* enemy2_ = nullptr;
	Enemy3* enemy3_ = nullptr;
	Enemy4* enemy4_ = nullptr;
	Enemy5* enemy5_ = nullptr;

};
