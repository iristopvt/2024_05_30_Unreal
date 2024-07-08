#include "pch.h"
#include "Bar.h"
#include "Objects/Arkano/Ball.h"

Bar::Bar()
{
	_bar = make_shared<RectCollider>(Vector2(650,550), Vector2(100,15)); // �� ũ��
	_ball = make_shared<Ball>(); // �� ����
	

	Move();
}

Bar::~Bar()
{
}

void Bar::Update()
{
	_bar->Update();
	_ball->Update();
	Move(); // �̵�
 	BallFire();

	if (!_ball->IsActive()) // �� ����� ��ġ 
	{
		_ball->Start(Vector2(_bar->_center._x, _bar->_center._y - 30));
	}

		BounceBall(_ball);
	

	
}

void Bar::Render(HDC hdc)
{
	_bar->Render(hdc);
	_ball->Render(hdc);
}

void Bar::Move()
{
	if (GetAsyncKeyState(VK_RIGHT)) // ���������� �̵�
	{
		_bar->_center._x += 5.0f* _speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) // �������� �̵�
	{
		_bar->_center._x -= 5.0f* _speed;

	}


}


void Bar::BallFire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
		if (!_ball->IsActive()) 
		{
			_ball->Fire(Vector2(0, -1)); // �� �߻�
		}
	}
}

void Bar::BounceBall(shared_ptr<Ball> ball)
{

	if (_bar->IsCollision(ball->GetCollider()) == false)
		return;

	Vector2 ballPos = ball->GetCollider()->_center;
	Vector2 bar = _bar->_center;

	Vector2 dir = ballPos - bar;
	dir.Normalize();

	ball->SetDir(dir);
}


// �����
//void Bar::Iscollistion(shared_ptr<Ball> ball)
//{
//	/*if (ball->GetDir().Length() <= 0.001f)
//	{
//		return;
//	}*/
//
//	if (_bar->IsCollision(ball->GetCollider()) == false)
//		return;
//
//	Vector2 ballPos = ball->GetCollider()->_center;
//	Vector2 bar = _bar->_center;
//
//	Vector2 dir = ballPos - bar;
//	dir.Normalize();
//
//	ball->SetDir(dir);
//}
