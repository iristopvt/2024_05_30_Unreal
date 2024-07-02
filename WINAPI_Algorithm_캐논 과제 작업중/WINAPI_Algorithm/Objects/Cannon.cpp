#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"


Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.f); // 몸 크기 
	_barrel = make_shared<Barrel>();
	//_bullet = make_shared<Bullet>();
	
	for (int i = 0; i < 1; i++) // 기존 볼렛 30에서1로 설정 
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false);
		_bullets.push_back(bullet);
	}

	Move();
}

Cannon::~Cannon()
{
}

void Cannon::Update() // 시작시 구동  ? 
{

	if (!IsActive)
	{
		return;
	}

	if (isControlled)
	{

	Move();
	Fire();
	}

	_body->Update();
	_barrel->Update();

	for (auto bullet : _bullets)
		bullet->Update();


}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
		bullet->Render(hdc);
	

}

void Cannon::Move() // 방향키 
{
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_angle += 0.01f;
	}


	_barrel->SetAngle(_angle); // 주포
	_barrel->SetStartI(_body->_center); // 주포 
	

}

void Cannon::Fire()
{
	
	// KEY DOWN

	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	{
	//	for (auto bullet : _bullets)
	//	{
	//		if (bullet->ISActive() == false)
	//		{
	//			bullet->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
	//			//bullet->SetActive(true);
	//			break;

	//		}
	//		//_bullets.reserve();
	//	}
		//_bullets->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
		
		// 두번째 방법
		/*auto iter = std::find_if(_bullets.begin(), _bullets.end(), [](shared_ptr<Bullet> bullet)->bool
			{
				if (bullet->ISActive()) return true;
				return false;

				if (iter != _bullets.end())
				{
					(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
								_bulletcnt++;

				}
			});*/
	
		// _bullets 꺼진 애(isActive == false)가 있는지 확인
		// -> 꺼진 애를 찾아서 fire

		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
			[](shared_ptr<Bullet> bullet)->bool
			{
				if (!bullet->ISActive()) return true;
				return false;
			});

		if (iter != _bullets.end())
		{
			(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
			_bulletcnt++;
		}

	}

}

void Cannon::TakeDamage()
{
	_Hp--;

	if (Dead())
	{
		IsActive = false;
	}

}


