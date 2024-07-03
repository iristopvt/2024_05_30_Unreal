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

	void Fire(Vector2 startpos, Vector2 direction);  // �Ѿ� �߻�
	void Attack_connom(shared_ptr<class Bar> bar);


	void SetActive(bool isActive); // �Ѿ� Ȱ��ȭ/��Ȱ��ȭ ����
	bool ISActive() { return _isActive; }// �Ѿ� Ȱ��ȭ ���� Ȯ��

private:
	shared_ptr<Collider> _ball;
	shared_ptr<Bar> _bar;
	
	Vector2 _direction = Vector2(0, 1); //  ���� 
	float _speed = 7.0f; // 
	bool _isActive = false;
	Vector2 _downVector = Vector2();

	float _lifeTime = 0.0f;
	float _delayTime = 3.0f;



};

