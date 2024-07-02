#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();

	bool Dead() { return _Hp <= 0; }
	bool IsActive = true;
	void TakeDamage();
	bool CanControl = true;

	bool isControlled = false;
	int GetBulletcnt() { return _bulletcnt; }
	void Bulletcnt() { _bulletcnt = 0; }



	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; } //???

private:
	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;
	//shared_ptr<CircleCollider> _col;
	int _Hp=5; 
	
	int _bulletcnt = 0;

	float _angle = 0.0f;
};

