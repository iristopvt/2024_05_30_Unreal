#pragma once

#define GRENN_COLOR		  0
#define RED_COLOR		  1

class CircleCollider
{
public:
	CircleCollider(Vector2 center, int radlian);
	~CircleCollider();
	

	void Update();
	void Render(HDC hdc);

	bool Iscollision(Vector2 point);
	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<RectCollider> other);

	void SetGreen() { SetColor(GRENN_COLOR); }
	void SetRed() { SetColor(RED_COLOR); }



public:
	// 멤버?
	void SetColor(ColorNum num);

	vector<HPEN> _pens;
	HPEN _curpen;
	Vector2 _center;
	int _radlian;
};

