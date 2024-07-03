#include "pch.h"
#include "Bar.h"
#include "Objects/Arkano/Ball.h"

Bar::Bar()
{
	_bar = make_shared<RectCollider>(Vector2(650,550), Vector2(100,15)); // 바 크기
	_ball = make_shared<Ball>(); // 공 생성

	
	Move();
}

Bar::~Bar()
{
}

void Bar::Update()
{
	_bar->Update();
	Move(); // 이동
	_ball->Update();
	//_ball->Attack_connom(); // 공과 바의 충돌 검사

	
}

void Bar::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);
}

void Bar::Move()
{
	if (GetAsyncKeyState(VK_RIGHT)) // 오른쪽으로 이동
	{
		_bar->_center._x += 5.0f;
		//_bar->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT)) // 왼쪽으로 이동
	{
		_bar->_center._x -= 5.0f;

		//_bar->_center._x -= 1.0f;
	}

	_ball->SetStart(_bar->_center);
}

void Bar::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{

	}
}

void Bar::SetStart(Vector2 start)
{
	_bar->_halfSize = start;
}


void Bar::BounceBall(shared_ptr<Ball> ball)
{
	if (_bar->IsCollision(ball->GetCollider()))
	{
		Vector2 ballCenter = ball->GetCenter();
		Vector2 barCenter = _bar->_center;
		Vector2 barSize = _bar->_halfSize;

		// 공이 바의 상단과 충돌했을 때의 처리
		if (ballCenter._y > barCenter._y - barSize._y && ballCenter._y < barCenter._y + barSize._y)
		{
			// 공의 수직 방향 반전
			ball->ReflectY();

			// 공의 수평 방향 조정
			float hitPosition = (ballCenter._x - barCenter._x) / barSize._x;
			ball->SetDirection(Vector2(hitPosition, -1.0f).Normalize()); // 반사 각도 조정
		}
	}

}
