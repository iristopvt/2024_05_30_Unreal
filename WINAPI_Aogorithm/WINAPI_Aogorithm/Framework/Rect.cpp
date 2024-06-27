#include "pch.h"
#include "Rect.h"

#include "Vector2.h"

Rect::Rect(Vector2 center, Vector2 halfSize)
	: _center(center) , _halfsize(halfSize)
{
}



void Rect::Update()
{

}

void Rect::Render(HDC hdc)
{
	int left = _center._x - _halfsize._x;
	int right = _center._x + _halfsize._x;
	int top = _center._y - _halfsize._y;
	int bottom = _center._y + _halfsize._y;

	Rectangle(hdc, left, top, right, bottom);
}
