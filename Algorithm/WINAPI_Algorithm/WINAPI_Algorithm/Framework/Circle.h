#pragma once
class Circle
{
public:
	Circle(Vector2 center, int radlian);
	~Circle() {}
	

	void Update();
	void Render(HDC hdc);
public:
	// 멤버?
	Vector2 _center;
		int _radlian;
};

