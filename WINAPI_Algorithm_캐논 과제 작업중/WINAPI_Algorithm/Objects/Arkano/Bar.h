#pragma once

class Ball;
class Bar
{
public:
	Bar();
	~Bar();

	void Update();
	void Render(HDC hdc);

	void Move(); 
	void Fire();
	bool isControlled = false; // 현재 조작 중인지 

	void SetStart(Vector2 start);

	
	void BounceBall(shared_ptr<Ball> ball);

	shared_ptr<Collider> GetCollider() { return _bar; } // 충돌체 반환
	
private:
	shared_ptr<RectCollider> _bar;

	float _barrelLength = 100.0f; // 길이
	shared_ptr<Ball> _ball;

};

