#include "pch.h"
#include "ArkanoidScene.h"
#include "Objects/Arkano/Ball.h"
#include "Objects/Arkano/Bar.h"
#include "Objects/Arkano/Brick.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<Bar>(); // ¹Ù
	_brick = make_shared<Brick>();
//	_ball = make_shared<Ball>();
	//_bar = make_shared<Bar>(); // ¹Ù
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	_brick->Update();
	//_bar->Iscollistion(_ball);

	//_bar->BallFire();
	//_ball->Update();
	if (_bar->GetBall()->IsActive())
	{
		_brick->Ballaway(_bar->GetBall());
	}

	
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
	_brick->Render(hdc);
}
