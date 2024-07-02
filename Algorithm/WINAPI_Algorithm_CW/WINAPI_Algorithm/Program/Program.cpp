#include "pch.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
Program::Program()
{
	_scene = make_shared<CollisionScene>(); // make_shared �ȿ� �ִ°� 
	//PaintScene�� CollisionScene�� �ٲٸ� �ٸ��� �����
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	_scene->Render(hdc);
}
