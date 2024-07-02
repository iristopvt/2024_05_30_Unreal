#pragma once
class Cannon
{
public:
	Cannon();
	~Cannon();

	void Update(); //상태 업데이트
	void Render(HDC hdc); //화면 렌더링

	void Move(); // 이동
	void Fire(); // 공격

	bool Dead() { return _Hp <= 0; } // 캐논이 죽었는지 
	bool IsActive = true; // 활성화 상태
	void TakeDamage(); // 받는 데미지
	bool CanControl = true; // 조작 가능 여부

	bool isControlled = false; // 현재 조작 중인지 
	int GetBulletcnt() { return _bulletcnt; } // 발사된 총알 개수 반환
	void Bulletcnt() { _bulletcnt = 0; } // 총알 초기화


	 
	shared_ptr<Collider> GetCollider() { return _body; } // 충돌체 반환
	vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; } // 총알 벡터 반환

private:
	shared_ptr<Collider> _body; // 몸
	shared_ptr<class Barrel> _barrel; // 배럴

	vector<shared_ptr<class Bullet>> _bullets; // 총알
	COLORREF _borderColor = RGB(0, 0, 255); // 초기 색상 파란색

	int _Hp=5; // 캐논 체력 
	int _bulletcnt = 0; // 총알 개수

	float _angle = 0.0f; //회전 각도 ?
};

