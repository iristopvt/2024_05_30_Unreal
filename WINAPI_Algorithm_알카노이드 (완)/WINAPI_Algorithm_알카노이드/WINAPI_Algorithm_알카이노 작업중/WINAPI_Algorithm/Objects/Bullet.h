#pragma once

class Collider;

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render(HDC hdc);

	void Fire(Vector2 startpos,Vector2 direction);  // �Ѿ� �߻�

	void SetActive(bool isActive); // �Ѿ� Ȱ��ȭ/��Ȱ��ȭ ����
	bool ISActive() {return _isActive; }// �Ѿ� Ȱ��ȭ ���� Ȯ��

	bool IsOut();
	void OutControll();

	// Attack 1
	void Attack_connom(shared_ptr<class Cannon> cannon);
	
	// Attack 2 
	void Attack_cannon();
	void SetTarget(shared_ptr<Cannon> cannon) { _target = cannon; } // 

private:
	bool _isActive = false;
	shared_ptr<Collider> _col; // �Ѿ� �浹ü
	Vector2 _direction = Vector2(1,0); // �Ѿ� ���� 
	float _speed = 7.0f; // 

	Vector2 _downVector = Vector2();

	float _lifeTime = 0.0f;
	float _delayTime = 3.0f;

	// Attack2

	weak_ptr<Cannon> _target; // weak_ptr �� ��ȯ���� �ذ��Ϸ� �� 
};

