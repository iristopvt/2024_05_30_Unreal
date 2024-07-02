#include "pch.h"
#include "Rect.h"



RectCollider::RectCollider(Vector2 center, Vector2 halfSize)
: _center(center), _halfSize(halfSize)
{
	_pens.push_back(CreatePen(PS_SOLID, 3, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 3, RED));

	SetColor(GRENN_COLOR);
	//_curpen = _pens[GRENN_COLOR];
}

RectCollider::~RectCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
	

}

void RectCollider::Update()
{
	//Iscollision(_halfSize);

}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curpen);

	int left = _center._x - _halfSize._x;
	int right = _center._x + _halfSize._x;
	int top = _center._y - _halfSize._y;
	int bottom = _center._y + _halfSize._y;

	Rectangle(hdc,left,top,right,bottom);
}

bool RectCollider::Iscollision(Vector2 point)
{
	// 포인터 .x가 left,right 사이에 있냐? 
	if (point._x < Right() && point._x > Left())
	{
		// 포인터 .y가 top, bottom 사이에 있냐?
		if (point._y < Bottom() && point._y > Top())
		{
			return true;
		}
	}


	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	/*float initialArea = 2 * _halfSize._x * 2 * _halfSize._y;
	float distance = _center.Distance(other->_center);*/


	return other->IsCollision(shared_from_this());
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	// 
	if (Right() < other->Left() || Left() > other->Right())
		return true;
	if (Bottom() < other->Top() || Top() > other->Bottom())
		return true;

	return false;
	//if (Right() > other->Left() && Left() < other->Right())
	//{
	//	if (Bottom() > other->Top() && Top() < other->Bottom())
	//	{
	//		return true;
	//	}
	//}


	//return false;
}

void RectCollider::SetColor(ColorNum num)
{
	_curpen = _pens[num];


}
