#include "pch.h"
#include "Brick.h"

#include "Objects/Maze/Block.h"
#include "Objects/Arkano/Ball.h"

Brick::Brick()
{
	// 블록 공 충돌후 블록 삭제 처리 

	//for (int i = 0; i < MAXCOUNT_Y; i++)
	//{
	//		_brick = make_shared<RectCollider>(Vector2(100, 50), Vector2(50, 15)); // 바 크기
	//}

	Vector2 offset = Vector2(200, 30);

	_blocks.reserve(MAXCOUNT_Y);

	for (int i = 0; i < MAXCOUNT_Y; i++)
	{
		vector<shared_ptr<Block>> blocks_X;
		blocks_X.reserve(MAXCOUNT_X);

		for (int j = 0; j < MAXCOUNT_X; j++)
		{
			Vector2 blockoffset = offset + Vector2(120.0f * j, 70.0f * i);

			shared_ptr<Block> block = make_shared<Block>();
			block->SetPosition(blockoffset);
			blocks_X.push_back(block);
		}
		_blocks.push_back(blocks_X);

	}
}

Brick::~Brick()
{
}

void Brick::Update()
{
	//_brick->Update();
	for (auto blocks_X : _blocks)
	{
		for (auto block : blocks_X)
		{
			block->Update();
		}
	}
}

void Brick::Render(HDC hdc)
{
	//_brick->Render(hdc);
	for (auto blocks_X : _blocks)
	{
		for (auto block : blocks_X)
		{
			block->Render(hdc);
		}
	}
}

void Brick::Ballaway(shared_ptr<class Ball> ball)
{


	for (auto& blocks_X : _blocks)
	{
		for (auto& block : blocks_X)
		{
			if (block->IsActive() && block->IsCollision(ball->GetCollider()))
			{
				block->SetActive(false); // 블록을 비활성화 상태로 설정

				Vector2 ballDir = ball->GetDir();
				ballDir._y *= -1.0f; // 공의 방향을 반전시킴
				ball->SetDir(ballDir);
				return;
			}
		}
	}


}
