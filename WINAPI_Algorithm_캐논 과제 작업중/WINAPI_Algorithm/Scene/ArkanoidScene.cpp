#include "pch.h"
#include "ArkanoidScene.h"
#include "Objects/Arkano/Ball.h"
#include "Objects/Arkano/Bar.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<Bar>(); // ¹Ù
//	_ball = make_shared<Ball>();
	//_bar = make_shared<Bar>(); // ¹Ù
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_bar->Update();
	//_ball->Update();
	
}

void ArkanoidScene::Render(HDC hdc)
{
	_bar->Render(hdc);
	//_ball->Render(hdc);
}
