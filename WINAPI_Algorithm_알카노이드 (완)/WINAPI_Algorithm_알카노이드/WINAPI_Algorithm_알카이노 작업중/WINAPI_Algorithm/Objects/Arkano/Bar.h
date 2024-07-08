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
	void BallFire();
	void BounceBall(shared_ptr<Ball> ball);

	shared_ptr<RectCollider> GetCollider() { return _bar; } // 충돌체 반환
	shared_ptr<Ball> GetBall() { return _ball; } // 공 객체를 반환하는 함수 추가

	//void Iscollistion(shared_ptr<Ball> ball); // 강사님

private:
	shared_ptr<RectCollider> _bar;
	shared_ptr<Ball> _ball;

	shared_ptr<RectCollider> _brick;
	float _speed = 1.5f;

};

