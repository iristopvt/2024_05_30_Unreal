#include "pch.h"
#include "Bullet.h"
#include "Objects/Cannon.h"
#include "Framework/Collider.h"

Bullet::Bullet()
{
	_col = make_shared<CircleCollider>(CENTER, 15); // ��ź ũ�� ���� 
	

}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false) return; 
	
	Attack_cannon(); //ĳ�� ���� 

	_col->Update();
	_col->_center += _direction * _speed;

	// TODO (����) : �߷� ���� 
	//_col->_center += _downVector;
	//_downVector += Vector2(0, 1) * GRAVITY;

	// TODO (����) : ȭ�� ������ ������ �� ������� �ڵ�
	//bool isout = IsOut();
	// OutControll �� �ݻ縦 ���� �Լ� 
	OutControll();
	bool isout = false;
	if (_lifeTime > _delayTime || isout)
	{
		_lifeTime = 0.0f;
		_isActive = false;
	}

	_lifeTime += 0.01f;
}

void Bullet::Render(HDC hdc)
{
	if (_isActive == false) return;

	_col->Render(hdc);
}

void Bullet::Fire(Vector2 startpos, Vector2 direction)
{
	_isActive = true;
	_col->_center = startpos;
	_direction = direction;
	_direction.Normalize();
	_downVector = Vector2();
	//Attack_connom(cannon);
}

void Bullet::SetActive(bool isActive)
{
	_downVector = Vector2();
	_isActive = isActive;
}

bool Bullet::IsOut()
{
	if (_col->_center._x > WIN_WIDTH || _col->_center._x < 0)
		return true;

	if (_col->_center._y > WIN_HEIGHT || _col->_center._y < 0)
		return true;

		return false;
}

void Bullet::OutControll()
{
	//// ȭ�� �¿�� ������ ?
	

	Vector2 center = _col->_center;
	if (center._x > WIN_WIDTH || center._x < 0)
	{
		_direction._x *= -1.0f;
	}
	if (center._y > WIN_HEIGHT || center._y < 0)
	{
		_direction._y *= -1.0f;
	}
}

void Bullet::Attack_connom(shared_ptr<class Cannon> cannon)
{

	//cannon�� ��� ������ ���ΰ� ?
	
	//float distance = cannon->_
	//_col->_center 

	// Attack_cannon �� ���� 
	//if (ISActive == false) return ;
	if(ISActive() == false)
	return;
	if (cannon->GetCollider()->IsCollision(_col))
	{
		SetActive(false);
		//Fire(cannon->_barrel->GetEndPos(), _barrel->GetDirection());
		
	}

}

void Bullet::Attack_cannon() //ĳ�� ���ݺκ� 
{
	//if (_target.expired() == false)
	//{
	//	shared_ptr<Cannon> targetCannon = _target.lock();
	//	shared_ptr<Collider> targetcannon1 = targetCannon->GetCollider();
	//	if (/*_target.lock()->GetCollider()->IsCollision(_col)*/
	//		targetcannon1->IsCollision(_col))
	//	{
	//		targetCannon->TakeDamage(); // ������ ������ �Դ°� 
	//		SetActive(false);
	//	}
	//}

	if (!_target.expired()) {
		auto targetCannon = _target.lock();
		auto targetCollider = targetCannon->GetCollider();
		if (targetCollider->IsCollision(_col)) {
			targetCannon->TakeDamage(); // �浹 �� ������ ó��
			SetActive(false); // �Ѿ� ��Ȱ��ȭ
		}
	}


}
