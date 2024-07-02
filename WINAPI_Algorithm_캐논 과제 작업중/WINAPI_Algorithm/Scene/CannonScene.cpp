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
	_cannon1->isControlled = true;
	
	// Attack 2 
	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
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

	if (!_cannon1->Dead() || !_cannon2->Dead())
	{
		if (_cannon1->isControlled)
		{
			if (_cannon1->GetBulletcnt() >= 1)
			{
			_cannon1->isControlled = false;
			_cannon2->isControlled = true;
			_cannon1->Bulletcnt();

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
