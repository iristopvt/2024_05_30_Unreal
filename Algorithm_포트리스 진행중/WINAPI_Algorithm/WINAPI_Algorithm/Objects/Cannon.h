#pragma once
class Cannon
{
public:
	Cannon(int hp, int atk);
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	void Move();
	void Fire();

	bool isControlled = false;

	shared_ptr<Collider> GetCollider() { return _body; }
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

	void TakeDamage(int amount);
	

private:

	shared_ptr<Collider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Bullet>> _bullets;
	int _curHp;
	int _maxHp;
	int _atk;

	float _angle = 0.0f;
};

