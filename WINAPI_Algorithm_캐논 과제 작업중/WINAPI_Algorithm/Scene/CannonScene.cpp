#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// 사양서
// 턴제 포트리스 -- 
// 각 cannon을 턴마다 서로 컨트롤을 받아서 공격 -- // cannon2 가 공격하는건 cannon1를 통과함 
// 
// cannon의 HP는 5
// 맞으면 HP -1, hp가 0이면 cannon이 사라짐

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();
	//_cannon1->TakeDamage()
	_cannon1->isControlled = true; // 캐논 1 조종 

	// Attack 2 
	for (auto bullet : _cannon1->GetBullets()) 
	{
		bullet->SetTarget(_cannon2); // 캐논 1 총알의 타겟 캐논 2 설정 
	}

	for (auto bullet : _cannon2->GetBullets()) {
		bullet->SetTarget(_cannon1); // 캐논 2 총알 타겟 캐논 1 설정 
	}
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();
	//_cannon1->Move();

	if (_cannon1->Dead()) {
		// _cannon1을 삭제하기 전에 다음과 같이 처리할 수 있습니다.
		// 예를 들어, 객체 포인터를 해제하고 해당 캐논의 메모리를 해제합니다.
		_cannon1 = nullptr; // 혹은 다른 방식으로 포인터를 초기화하거나 해제합니다.
		// delete _cannon1; // 사용할 수 있는 경우에만 사용하세요 (shared_ptr와 호환되지 않음)
	}
	if (!_cannon1->Dead() || !_cannon2->Dead())
	{
		if (_cannon1->isControlled)
		{
			if (_cannon1->GetBulletcnt() >= 1)
			{
			_cannon1->isControlled = false; // 캐논 1 조종 종료
			_cannon2->isControlled = true; // 캐논 2 조종 시작
			_cannon1->Bulletcnt(); // 총알 초기화 

			}
			
		}
		else
		{
			if (_cannon2->GetBulletcnt() >= 1)
			{
				_cannon2->isControlled = false;
				_cannon1->isControlled = true;
				_cannon2->Bulletcnt();
			}
		}
		
	}
	// Attack 1 
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_connom(_cannon2);
	//}
	

	/*if (!_cannon1->IsDead() || !_cannon2->IsDead())
	{
		if (_cannon1->isControlled)
		{
			if (_cannon1->GetBulletcnt() >= 3)
			{
				_cannon1->isControlled = false;
				_cannon2->isControlled = true;
				_cannon1->ResetBulletcnt();
			}
		}
		else
		{
			if (_cannon2->GetBulletcnt() >= 3)
			{
				_cannon2->isControlled = false;
				_cannon1->isControlled = true;
				_cannon2->ResetBulletcnt();
			}
		}*/
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);

}
