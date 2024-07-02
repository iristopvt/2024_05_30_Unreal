#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update(); //���� ������Ʈ
	void Render(HDC hdc); //ȭ�� ������

	void Move(); // �̵�
	void Fire(); // ����

	bool Dead() { return _Hp <= 0; } // ĳ���� �׾����� 
	bool IsActive = true; // Ȱ��ȭ ����
	void TakeDamage(); // �޴� ������
	bool CanControl = true; // ���� ���� ����

	bool isControlled = false; // ���� ���� ������ 
	int GetBulletcnt() { return _bulletcnt; } // �߻�� �Ѿ� ���� ��ȯ
	void Bulletcnt() { _bulletcnt = 0; } // �Ѿ� �ʱ�ȭ


	 
	shared_ptr<Collider> GetCollider() { return _body; } // �浹ü ��ȯ
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; } // �Ѿ� ���� ��ȯ

private:
	shared_ptr<Collider> _body; // ��
	shared_ptr<class Barrel> _barrel; // �跲

	vector<shared_ptr<class Bullet>> _bullets; // �Ѿ�
	COLORREF _borderColor = RGB(0, 0, 255); // �ʱ� ���� �Ķ���

	int _Hp=5; // ĳ�� ü�� 
	int _bulletcnt = 0; // �Ѿ� ����

	float _angle = 0.0f; //ȸ�� ���� ?
};

