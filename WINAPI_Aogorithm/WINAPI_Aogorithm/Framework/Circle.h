#pragma once
class Circle
{
public:
	Circle(Vector2 center, float radlian);
	~Circle() {}


	void Update();
	void Render(HDC hdc);
public:
	// ���?
	Vector2 _center;
	float _radlian;
};

