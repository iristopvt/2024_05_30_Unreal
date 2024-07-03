#include "pch.h"
#include "ArkanoidScene.h"
#include "Objects/Arkano/Ball.h"
#include "Objects/Arkano/Bar.h"

ArkanoidScene::ArkanoidScene()
{
	_bar = make_shared<Bar>(); // ��
//	_ball = make_shared<Ball>();
	//_bar = make_shared<Bar>(); // ��
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
