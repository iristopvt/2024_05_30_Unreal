#pragma once


class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	bool IsOut();
	void OutControll();

	void SetStart(Vector2 start);

	void Fire(Vector2 startpos, Vector2 direction);  // 총알 발사
	void Attack_connom(shared_ptr<class Bar> bar);


	void SetActive(bool isActive); // 총알 활성화/비활성화 설정
	bool ISActive() { return _isActive; }// 총알 활성화 여부 확인

private:
	shared_ptr<Collider> _ball;
	shared_ptr<Bar> _bar;
	
	Vector2 _direction = Vector2(0, 1); //  방향 
	float _speed = 7.0f; // 
	bool _isActive = false;
	Vector2 _downVector = Vector2();

	float _lifeTime = 0.0f;
	float _delayTime = 3.0f;



};

