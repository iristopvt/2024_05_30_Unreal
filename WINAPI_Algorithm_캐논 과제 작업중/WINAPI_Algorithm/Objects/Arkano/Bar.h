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
	bool isControlled = false; // ���� ���� ������ 

	void SetStart(Vector2 start);

	
	void BounceBall(shared_ptr<Ball> ball);

	shared_ptr<Collider> GetCollider() { return _bar; } // �浹ü ��ȯ
	
private:
	shared_ptr<RectCollider> _bar;

	float _barrelLength = 100.0f; // ����
	shared_ptr<Ball> _ball;

};

