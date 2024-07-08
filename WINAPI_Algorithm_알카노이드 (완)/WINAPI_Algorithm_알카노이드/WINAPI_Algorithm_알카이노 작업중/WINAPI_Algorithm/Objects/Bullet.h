#pragma once

class Collider;

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 startpos,Vector2 direction);  // 총알 발사

	void SetActive(bool isActive); // 총알 활성화/비활성화 설정
	bool ISActive() {return _isActive; }// 총알 활성화 여부 확인

	bool IsOut();
	void OutControll();

	// Attack 1
	void Attack_connom(shared_ptr<class Cannon> cannon);
	
	// Attack 2 
	void Attack_cannon();
	void SetTarget(shared_ptr<Cannon> cannon) { _target = cannon; } // 

private:
	bool _isActive = false;
	shared_ptr<Collider> _col; // 총알 충돌체
	Vector2 _direction = Vector2(1,0); // 총알 방향 
	float _speed = 7.0f; // 

	Vector2 _downVector = Vector2();

	float _lifeTime = 0.0f;
	float _delayTime = 3.0f;

	// Attack2

	weak_ptr<Cannon> _target; // weak_ptr 는 순환참조 해결하려 씀 
};

