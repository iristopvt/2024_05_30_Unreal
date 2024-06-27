#pragma once

using ColorNum = int;
#define GRENN_COLOR		  0
#define RED_COLOR		  1
class RectCollider/*�浹ü*/ : public enable_shared_from_this<RectCollider>
{
public:
	RectCollider(Vector2 center, Vector2 halfSize);
	~RectCollider();

	void Update();
	void Render(HDC hdc);

	bool Iscollision(Vector2 point);
	bool IsCollision(shared_ptr<class CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

	float Left () {return _center._x - _halfSize._x;}
	float Right() { return _center._x + _halfSize._x; }
	float Top() { return _center._y - _halfSize._y; }
	float Bottom() { return _center._y + _halfSize._y; }




	void SetGreen() { SetColor(RED_COLOR); }
	void SetRed() { SetColor(GRENN_COLOR); }

public:
	void SetColor(ColorNum num);

	vector<HPEN> _pens;
	HPEN _curpen;

	Vector2 _center;
	Vector2 _halfSize;
};

