#pragma once


class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	

	void OutControll();
	void Start(Vector2 start);
	void Fire(Vector2 direction);  

	//Vector2 GetDir() const { return _direction; }
	void SetDir(Vector2 direction) { _direction = direction; }
	Vector2 GetDir() const { return _direction; }


	void SetActive(bool isActive); 
	bool IsActive() { return _isActive; }
	shared_ptr<CircleCollider> GetCollider() { return _ball; } // �� �浹 ��ȯ


private:
	shared_ptr<CircleCollider> _ball; 
	
	Vector2 _direction = Vector2(0, 0); //  ���� 
	float _speed = 8.0f; // 
	bool _isActive = false;
	Vector2 _downVector = Vector2();



};

