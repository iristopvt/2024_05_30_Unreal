#pragma once
class Rect
{
public:
	Rect(Vector2 center, Vector2 halfSize);

	~Rect(){}

	void Update();
	void Render(HDC hdc);


public:
	// center;
	Vector2 _center;
	Vector2 _halfsize;


};

