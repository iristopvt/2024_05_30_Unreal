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

	//_ball->_center += _downVector; // 중력
	//_downVector += Vector2(0, 1) * GRAVITY; // 중력

	//bool isout = IsOut();
	OutControll();
	bool isout = false;
	if (_lifeTime > _delayTime || isout)
	{
		_lifeTime = 0.0f;
		_isActive = false;
	}

	_lifeTime += 0.01f;

}

void Ball::Render(HDC hdc)
{
	//if (_isActive == false) return;
	_ball->Render(hdc);
}

bool Ball::IsOut()
{
	return false;
}

void Ball::OutControll()
{

	Vector2 center = _ball->_center;
	if (center._x > WIN_WIDTH || center._x < 0)
	{
		_direction._x *= -1.0f;
	}
	if (center._y > WIN_HEIGHT || center._y < 0)
	{
		_direction._y *= -1.0f;
	}
}

void Ball::SetStart(Vector2 start)
{
	_ball->_center._y ;
	//_ball->_center._x;
}

void Ball::Fire(Vector2 startpos, Vector2 direction)
{
	_isActive = true;
	_ball->_center = startpos;
	_direction = direction;
	_direction.Normalize();
	_downVector = Vector2();
}

void Ball::Attack_connom(shared_ptr<class Bar> bar)
{
	if (ISActive() == false)
		return;
	if (bar->GetCollider()->IsCollision(_ball))
	{
		//SetActive(false);
		Vector2 ballCenter = _ball->_center;
		//Vector2
		//Fire(cannon->_barrel->GetEndPos(), _barrel->GetDirection());

	}

	//if (!_isActive) return;
	//if (bar->GetCollider()->IsCollision(_ball))
	//{
	//	// 바와 충돌 시 공의 방향 변경
	//	Vector2 ballCenter = _ball->_center;
	//	Vector2 barCenter = bar->GetCollider()->_center;
	//	Vector2 barSize = _bar->GetCollider()->_halfSize;

	//	// 충돌 위치에 따라 반사각 조정
	//	if (ballCenter._y > barCenter._y - barSize._y && ballCenter._y < barCenter._y + barSize._y)
	//	{
	//		// 공이 바의 상단과 충돌
	//		_direction._y *= -1.0f; // 수직 방향 반전

	//		// 충돌 위치에 따라 반사각 조정
	//		float hitPosition = (ballCenter._x - barCenter._x) / barSize._x;
	//		_direction._x = hitPosition;
	//		_direction.Normalize(); // 방향 벡터 정규화
	//	}
	//}
}

void Ball::SetActive(bool isActive)
{
	_isActive = isActive;

}
