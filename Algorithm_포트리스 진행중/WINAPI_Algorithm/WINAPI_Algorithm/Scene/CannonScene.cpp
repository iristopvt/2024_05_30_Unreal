#include "pch.h"
#include "CannonScene.h"
#include "Objects/Cannon.h"
#include "Objects/Bullet.h"

// 사양서
// 턴제 포트리스
// 각 cannon을 턴마다 서로 컨트롤을 받아서 공격
// cannon의 HP는 5
// 맞으면 hp - 1, hp가 0이면 cannon이 사라짐

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

	//_cannon1->isControlled = false;

	// Attack2
	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
	}

	for (auto bullet : _cannon2->GetBullets())
	{
		bullet->SetTarget(_cannon1);
	}



}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

	
	_cannon1->Move(); // cannon1 움직임
	//_cannon1->Fire();  // cannon1 공격 

	// 각 캐논의 움직임과 공격은 move,fire를 불러와서 처리가 가능하니
	// if문으로 턴을 만들어서 처리를 해야함 


	_cannon2->Fire();
	 // 캐논 2 에 move가 없어 포신이 위쪽에 있음 



	//_cannon2->Move();
	
	// Attack1
	//for (auto bullet : _cannon1->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon2);
	//}

	//for (auto bullet : _cannon2->GetBullets())
	//{
	//	bullet->Attack_Cannon(_cannon1);
	//}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}
