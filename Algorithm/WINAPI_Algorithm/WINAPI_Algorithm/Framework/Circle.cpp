#include "pch.h"
#include "Circle.h"

Circle::Circle(Vector2 center, int radlian)
	: _center(center),_radlian(radlian)
{
}



void Circle::Update()
{

}

void Circle::Render(HDC hdc)
{
	int left = _center._x - _radlian;
	int right = _center._x + _radlian;
	int top = _center._y - _radlian;
	int bottom = _center._y + _radlian;
	Ellipse(hdc, left, top, right, bottom);
}
