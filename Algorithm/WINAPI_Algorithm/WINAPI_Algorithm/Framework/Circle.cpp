#include "pch.h"
#include "Circle.h"



CircleCollider::CircleCollider(Vector2 center, int radlian)
	: _center(center),_radlian(radlian)
{
	_pens.push_back(CreatePen(PS_SOLID, 5, GREEN));
	_pens.push_back(CreatePen(PS_SOLID, 5, RED));

	SetColor(GRENN_COLOR);

//	_curpen = _pens[GRENN_COLOR];
}

CircleCollider::~CircleCollider()
{
	for (auto pen : _pens)
		DeleteObject(pen);
}



void CircleCollider::Update()
{
	
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _curpen);


	int left = _center._x - _radlian;
	int right = _center._x + _radlian;
	int top = _center._y - _radlian;
	int bottom = _center._y + _radlian;

	Ellipse(hdc, left, top, right, bottom);
}
// 점 원
bool CircleCollider::Iscollision(Vector2 point)
{
	float distance = _center.Distance(point);

	return distance < _radlian;
}
// 원 원 
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	float distance = _center.Distance(other->_center);

	return distance < _radlian + other->_radlian;
}
// 사각형 원 
bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	// 과제

	// AABB(회전하지 않는다는 조건), OBB(회전이 가능하다)

	//float distance = _center.Distance(other->_center);

	float raLeft = other->Left() + _radlian; 
	float raRight = other->Right() + _radlian;
	float raTop = other->Top() + _radlian;
	float raBottom = other->Bottom() + _radlian;


	if (_radlian < raLeft || _radlian > raRight)
		return true;
	if (_radlian < raTop || _radlian > raBottom)
		return true;

	return false;
	//return false;
}


void CircleCollider::SetColor(ColorNum num)
{
	_curpen = _pens[num];

}
