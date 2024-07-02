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
	:_Turn(1), _isTurnEnd(false)
{
	_cannon1 = make_shared<Cannon>(Vector2(100, 300));  // 캐논 1의 초기 위치 설정
	_cannon2 = make_shared<Cannon>(Vector2(700, 300));  // 캐논 2의 초기 위치 설정

	//_cannon1 = make_shared<Cannon>();
	//_cannon2 = make_shared<Cannon>();

	//_cannon1->isControlled = false;

	// Attack2
	_isTurnEnd = false; 

	for (auto bullet : _cannon1->GetBullets())
	{
		bullet->SetTarget(_cannon2);
	}

	for (auto bullet : _cannon2->GetBullets())
	{
		bullet->SetTarget(_cannon1);
	}

	_Turn = 1;  // _cannon1의 턴부터 시작
	_isTurnEnd = false; // 초기에는 턴이 끝나지 않음

}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	shared_ptr<Cannon> currentCannon = (_Turn == 1) ? _cannon1 : _cannon2;
	shared_ptr<Cannon> otherCannon = (_Turn == 1) ? _cannon2 : _cannon1;

	// 현재 턴의 행동 수행
	currentCannon->Update();
	currentCannon->Move();  // 또는 Fire()

	if (CheckTurnEndCondition())
	{
		EndTurn();
	}

	// 다른 캐논도 업데이트
	otherCannon->Update();

	//_cannon1->Update();
	//_cannon2->Update();

	//_cannon2->Fire();

	//_cannon1->Move(); // cannon1 움직임

	//_cannon1->Fire();  // cannon1 공격 

	// 각 캐논의 움직임과 공격은 move,fire를 불러와서 처리가 가능하니
	// if문으로 턴을 만들어서 처리를 해야함 


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

void CannonScene::EndTurn()
{
	_isTurnEnd = false;  // 턴 종료 상태 초기화

	// 현재 턴을 다음 플레이어에게 넘김
	if (_Turn == 1)
	{
		_Turn = 2;
	}
	else
	{
		_Turn = 1;
	}
}

bool CannonScene::CheckTurnEndCondition()
{
	// 예를 들어, 현재 턴의 캐논이 행동을 완료했는지 확인
	shared_ptr<Cannon> currentCannon = (_Turn == 1) ? _cannon1 : _cannon2;

	// 현재 턴의 캐논이 이동 또는 공격을 완료했는지 확인하는 조건
	// 이 예제에서는 단순히 true를 반환
	return currentCannon->IsActionComplete();
}
