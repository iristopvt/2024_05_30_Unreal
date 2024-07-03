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
	Move(); // �̵�
	_ball->Update();
	//_ball->Attack_connom(); // ���� ���� �浹 �˻�

	
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
		_bar->_center._x += 5.0f;
		//_bar->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT)) // �������� �̵�
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

		// ���� ���� ��ܰ� �浹���� ���� ó��
		if (ballCenter._y > barCenter._y - barSize._y && ballCenter._y < barCenter._y + barSize._y)
		{
			// ���� ���� ���� ����
			ball->ReflectY();

			// ���� ���� ���� ����
			float hitPosition = (ballCenter._x - barCenter._x) / barSize._x;
			ball->SetDirection(Vector2(hitPosition, -1.0f).Normalize()); // �ݻ� ���� ����
		}
	}

}
