#include "pch.h"
#include "Barrel.h"

Barrel::Barrel()
{
	_line = make_shared<Line>(Vector2(),Vector2()); //배럴 선 초기화
	_line->_end = _line->_start + _direction * _barrelLength; //배럴 끝점 계산
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	_line->_end = _line->_start + _direction * _barrelLength; // 배럴 끝점 갱신

	_line->Update(); // 배럴 선 업데이트
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc); // 선 렌더링
}

void Barrel::SetStartI(Vector2 start)
{
	_line->_start = start; // 배럴 시작위치
}

void Barrel::SetAngle(float angle)
{
	_direction._x = cosf(angle);
	_direction._y = sinf(angle);
}

