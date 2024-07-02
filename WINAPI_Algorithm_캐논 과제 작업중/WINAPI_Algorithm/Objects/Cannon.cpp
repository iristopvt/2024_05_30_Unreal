#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"


Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.f); // 몸 크기 

	_barrel = make_shared<Barrel>(); // 배럴 생성
	//_bullet = make_shared<Bullet>();
	
	for (int i = 0; i < 1; i++) // 기존 볼렛 30에서1로 설정  // 총알 생성
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false); // 총알 비활성화 상태 초기화
		_bullets.push_back(bullet); // 총알 넣기
	}

	Move(); 
}

Cannon::~Cannon()
{
}

void Cannon::Update() // 시작시 구동  ? 
{

	if (!IsActive) // 캐논 활성화  체크 비활성화 상태면 업데이트 중단
	{
		return;
	}

	if (isControlled)
	{
	Move(); // 이동
	Fire(); // 공격 
	}

	_body->Update(); // 바디 업데이트
	_barrel->Update(); // 배럴 업데이트

	for (auto bullet : _bullets)
		bullet->Update(); // 총알 업데이트


}

void Cannon::Render(HDC hdc)
{
	if (!IsActive) // 캐논 활성화  체크 비활성화 상태면 렌더링 중단 
	{
		return;
	}

	/*_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
		bullet->Render(hdc);*/
	

	// 브러시와 펜을 생성하여 캐논의 색깔을 설정
	HBRUSH hBrush = CreateSolidBrush(_borderColor); // 테두리 색상 설정
	HPEN hPen = CreatePen(PS_SOLID, 1, _borderColor); // 테두리 펜 설정
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);

	// _body->Render(hdc); 대신 직접 그리기
	_barrel->Render(hdc); // 배럴 렌더링
	_body->Render(hdc); // 충돌체 렌더링 

	// 브러시와 펜을 원래대로 돌려놓고 삭제
	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);

	for (auto bullet : _bullets) 
	{
		bullet->Render(hdc); // 총알 렌더링
	}
}

void Cannon::Move() // 방향키 
{
	if (GetAsyncKeyState(VK_RIGHT)) // 오른쪽으로 이동
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT)) // 왼쪽으로 이동
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP)) // 배럴 위쪽으로 회전
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN)) // 배럴 아래쪽으로 회전
	{
		_angle += 0.01f;
	}


	_barrel->SetAngle(_angle); // 배럴의 각도 설정
	_barrel->SetStartI(_body->_center); // 배럴의 시작위치  
	

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
			(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection()); // 총알 발사  
			_bulletcnt++; // 발사후 총알 개수 증가
		}

	}

}

void Cannon::TakeDamage()
{
	_Hp--;

	switch (_Hp) {
	case 4:
		_borderColor = RGB(0, 255, 0); // 초록색
		break;
	case 3:
		_borderColor = RGB(255, 255, 0); // 노란색
		break;
	case 2:
		_borderColor = RGB(255, 165, 0); // 주황색
		break;
	case 1:
		_borderColor = RGB(255, 0, 0); // 빨간색
		break;
//	case 0:
	//	_borderColor = RGB(0, 0, 0); // 검정색 (파괴된 상태)
		break;
	default:
		_borderColor = RGB(0, 255, 0); // 초록색 (기본값)
		break;
	}

	
	if (Dead())
	{
		IsActive = false; // 캐논 비활성화 
	}

}


