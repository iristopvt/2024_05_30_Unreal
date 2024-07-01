#include "pch.h"
#include "Vector2.h"

float Vector2::Length() const // ����
{
	//return 0.0f;
	return sqrt(_x * _x + _y * _y); // sqrt ��Ʈ//  ��Ʈ x���� �÷��� y ����  
}

float Vector2::Distance(Vector2 other) const
{
	Vector2 temp = other - *this;

	return temp.Length();
}

void Vector2::Normalize() // ���͸� ���� ���ͷ� ����� ����? �־��� ������ ������ ���� �ϸ鼭 ������ ũ�⸦ 1 ��
{
    // ��Ʈ x���� �÷��� y ���� �п� x, ��Ʈ x���� �÷��� y ���� �п� y 
	float len = Length(); // ���� 
	_x /= len; // ��Ʈ x���� �÷��� y ���� �п� x
	_y /= len; // ��Ʈ x���� �÷��� y ���� �п� y 
}

Vector2 Vector2::NormalVector2() // ���� ���͸� �̾Ƴ��°�?  // ���� ����?  // ���ӿ����� ����ȭ�� ���͸� �븻 ���Ͷ���� 
{
	//float len = Length(); //  ����
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
