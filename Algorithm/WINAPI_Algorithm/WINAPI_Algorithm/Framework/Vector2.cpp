#include "pch.h"
#include "Vector2.h"

float Vector2::Length() const // ����
{
	//return 0.0f;
	return sqrt(_x * _x + _y * _y); // sqrt ��Ʈ//  ��Ʈ x���� �÷��� y ����  
}

void Vector2::Normalize() // ���͸� ���� ���ͷ� ����� ����? �־��� ������ ������ ���� �ϸ鼭 ������ ũ�⸦ 1 ��
{
    // ��Ʈ x���� �÷��� y ���� �п� x, ��Ʈ x���� �÷��� y ���� �п� y 
	float len = Length(); // ���� 
	_x /= len; // ��Ʈ x���� �÷��� y ���� �п� x
	_y /= len; // ��Ʈ x���� �÷��� y ���� �п� y 
}

Vector2 Vector2::NormalVector2()
{
	float len = Length(); //  ����
   //...?


	return Vector2();
}
