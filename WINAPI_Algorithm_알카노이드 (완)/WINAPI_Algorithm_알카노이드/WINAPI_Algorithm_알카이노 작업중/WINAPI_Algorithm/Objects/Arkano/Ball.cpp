#include "pch.h"
#include "Ball.h"
#include "Objects/Arkano/Bar.h"


Ball::Ball()
{
	_ball = make_shared<CircleCollider>(CENTER, 15);

}

Ball::~Ball()
{
}

void Ball::Update()
{
	/*if (_isActive == false) return;*/

	_ball->Update();  
	_ball->_center += _direction * _speed; 
	OutControll();

	
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}






void Ball::Start(Vector2 start)
{

	_ball->_center = start; // ���� �߽��� ������ġ ����
	_direction = Vector2(0, -1); // �� ���� �ʱ�ȭ
	_isActive = false; // �� ��Ȱ��ȭ
}

void Ball::Fire(Vector2 direction)
{
	_direction = direction;
	_direction.Normalize();
	_isActive = true;

}



void Ball::OutControll() // �� ȭ�� �𼭸� �浹 �ݻ� 
{

	Vector2 center = _ball->_center;
	if (center._x > WIN_WIDTH || center._x < 0)
	{
		_direction._x *= -1.0f;
	}
	if ( center._y < 0) 
	{
		_direction._y *= -1.0f;
	}
}

//center._y > WIN_HEIGHT || �̰� ������ �� �Ʒ��� �������� �����

void Ball::SetActive(bool isActive)
{
	_isActive = isActive;

}
