#include "pch.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
#include "Scene/Line2Scene.h"
#include "Scene/CannonScene.h"
#include "Scene/MazeScene.h"


HDC Program::backBufer = nullptr;
Program::Program()
{
	srand(time(nullptr));

	_scene = make_shared<CannonScene>();

	HDC hdc = GetDC(hWnd);

	backBufer = CreateCompatibleDC(hdc);
	_hBitMap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT);
	SelectObject(backBufer, _hBitMap);
}

Program::~Program()
{
	DeleteObject(backBufer);
	DeleteObject(_hBitMap);
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(backBufer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);
	
	_scene->Render(backBufer);

	BitBlt(
		hdc,
		0, 0,
		WIN_WIDTH, WIN_HEIGHT,
		backBufer,
		0, 0,
		SRCCOPY
	);

}
