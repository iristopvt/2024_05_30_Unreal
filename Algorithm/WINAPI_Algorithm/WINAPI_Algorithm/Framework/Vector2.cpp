#include "pch.h"
#include "Vector2.h"

float Vector2::Length() const // 길이
{
	//return 0.0f;
	return sqrt(_x * _x + _y * _y); // sqrt 루트//  루트 x제곱 플러스 y 제곱  
}

float Vector2::Distance(Vector2 other) const
{
	Vector2 temp = other - *this;

	return temp.Length();
}

void Vector2::Normalize() // 벡터를 단위 벡터로 만드는 과정? 주어진 벡터의 방향은 유지 하면서 벡터의 크기를 1 로
{
    // 루트 x제곱 플러스 y 제곱 분에 x, 루트 x제곱 플러스 y 제곱 분에 y 
	float len = Length(); // 길이 
	_x /= len; // 루트 x제곱 플러스 y 제곱 분에 x
	_y /= len; // 루트 x제곱 플러스 y 제곱 분에 y 
}

Vector2 Vector2::NormalVector2() // 단위 벡터를 뽑아내는것?  // 곱셈 벡터?  // 게임에서는 정규화된 벡터를 노말 벡터라고함 
{
	//float len = Length(); //  길이
   //...?
	Vector2 result = *this;
	result.Normalize();

	return result;
}

bool Vector2::IsBetween(Vector2 v1, Vector2 v2)
{
	float Cross1 = this->Cross(v1); // +
	float Cross2 = this->Cross(v2); // -

	bool result = (Cross1 * Cross2) < 0;

	return false;
}

float Vector2::initialArea()
{
	return 0.0f;
}
