#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"


Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(CENTER, 50.f); // �� ũ�� 

	_barrel = make_shared<Barrel>(); // �跲 ����
	//_bullet = make_shared<Bullet>();
	
	for (int i = 0; i < 1; i++) // ���� ���� 30����1�� ����  // �Ѿ� ����
	{
		shared_ptr<Bullet> bullet = make_shared<Bullet>();
		bullet->SetActive(false); // �Ѿ� ��Ȱ��ȭ ���� �ʱ�ȭ
		_bullets.push_back(bullet); // �Ѿ� �ֱ�
	}

	Move(); 
}

Cannon::~Cannon()
{
}

void Cannon::Update() // ���۽� ����  ? 
{

	if (!IsActive) // ĳ�� Ȱ��ȭ  üũ ��Ȱ��ȭ ���¸� ������Ʈ �ߴ�
	{
		return;
	}

	if (isControlled)
	{
	Move(); // �̵�
	Fire(); // ���� 
	}

	_body->Update(); // �ٵ� ������Ʈ
	_barrel->Update(); // �跲 ������Ʈ

	for (auto bullet : _bullets)
		bullet->Update(); // �Ѿ� ������Ʈ


}

void Cannon::Render(HDC hdc)
{
	if (!IsActive) // ĳ�� Ȱ��ȭ  üũ ��Ȱ��ȭ ���¸� ������ �ߴ� 
	{
		return;
	}

	/*_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto bullet : _bullets)
		bullet->Render(hdc);*/
	

	// �귯�ÿ� ���� �����Ͽ� ĳ���� ������ ����
	HBRUSH hBrush = CreateSolidBrush(_borderColor); // �׵θ� ���� ����
	HPEN hPen = CreatePen(PS_SOLID, 1, _borderColor); // �׵θ� �� ����
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);

	// _body->Render(hdc); ��� ���� �׸���
	_barrel->Render(hdc); // �跲 ������
	_body->Render(hdc); // �浹ü ������ 

	// �귯�ÿ� ���� ������� �������� ����
	SelectObject(hdc, oldBrush);
	SelectObject(hdc, oldPen);
	DeleteObject(hBrush);
	DeleteObject(hPen);

	for (auto bullet : _bullets) 
	{
		bullet->Render(hdc); // �Ѿ� ������
	}
}

void Cannon::Move() // ����Ű 
{
	if (GetAsyncKeyState(VK_RIGHT)) // ���������� �̵�
	{
		_body->_center._x += 1.0f;
	}
	if (GetAsyncKeyState(VK_LEFT)) // �������� �̵�
	{
		_body->_center._x -= 1.0f;
	}
	if (GetAsyncKeyState(VK_UP)) // �跲 �������� ȸ��
	{
		_angle -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN)) // �跲 �Ʒ������� ȸ��
	{
		_angle += 0.01f;
	}


	_barrel->SetAngle(_angle); // �跲�� ���� ����
	_barrel->SetStartI(_body->_center); // �跲�� ������ġ  
	

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
		
		// �ι�° ���
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
	
		// _bullets ���� ��(isActive == false)�� �ִ��� Ȯ��
		// -> ���� �ָ� ã�Ƽ� fire

		auto iter = std::find_if(_bullets.begin(), _bullets.end(),
			[](shared_ptr<Bullet> bullet)->bool
			{
				if (!bullet->ISActive()) return true;
				return false;
			});

		if (iter != _bullets.end())
		{
			(*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection()); // �Ѿ� �߻�  
			_bulletcnt++; // �߻��� �Ѿ� ���� ����
		}

	}

}

void Cannon::TakeDamage()
{
	_Hp--;

	switch (_Hp) {
	case 4:
		_borderColor = RGB(0, 255, 0); // �ʷϻ�
		break;
	case 3:
		_borderColor = RGB(255, 255, 0); // �����
		break;
	case 2:
		_borderColor = RGB(255, 165, 0); // ��Ȳ��
		break;
	case 1:
		_borderColor = RGB(255, 0, 0); // ������
		break;
//	case 0:
	//	_borderColor = RGB(0, 0, 0); // ������ (�ı��� ����)
		break;
	default:
		_borderColor = RGB(0, 255, 0); // �ʷϻ� (�⺻��)
		break;
	}

	
	if (Dead())
	{
		IsActive = false; // ĳ�� ��Ȱ��ȭ 
	}

}


