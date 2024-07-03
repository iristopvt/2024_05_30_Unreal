#include "pch.h"
#include "Barrel.h"

Barrel::Barrel()
{
	_line = make_shared<Line>(Vector2(),Vector2()); //�跲 �� �ʱ�ȭ
	_line->_end = _line->_start + _direction * _barrelLength; //�跲 ���� ���
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	_line->_end = _line->_start + _direction * _barrelLength; // �跲 ���� ����

	_line->Update(); // �跲 �� ������Ʈ
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc); // �� ������
}

void Barrel::SetStartI(Vector2 start)
{
	_line->_start = start; // �跲 ������ġ
}

void Barrel::SetAngle(float angle)
{
	_direction._x = cosf(angle);
	_direction._y = sinf(angle);
}

