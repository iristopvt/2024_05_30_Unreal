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

	shared_ptr<RectCollider> GetCollider() { return _bar; } // �浹ü ��ȯ
	shared_ptr<Ball> GetBall() { return _ball; } // �� ��ü�� ��ȯ�ϴ� �Լ� �߰�

	//void Iscollistion(shared_ptr<Ball> ball); // �����

private:
	shared_ptr<RectCollider> _bar;
	shared_ptr<Ball> _ball;

	shared_ptr<RectCollider> _brick;
	float _speed = 1.5f;

};

