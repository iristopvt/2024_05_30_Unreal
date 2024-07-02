#include "pch.h"
#include "Cannon.h"
#include "Objects/Barrel.h"
#include "Objects/Bullet.h"

Cannon::Cannon(Vector2 initialPosition)
    : _curHp(5), _maxHp(5), _isActionComplete(false), _angle(0.0f)
{
    _body = make_shared<CircleCollider>(initialPosition, 50.0f);
    _barrel = make_shared<Barrel>();

    for (int i = 0; i < 30; i++)
    {
        shared_ptr<Bullet> bullet = make_shared<Bullet>();
        bullet->SetActive(false);
        _bullets.push_back(bullet);
    }
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
    _body->Update();
    _barrel->Update();

    for (auto bullet : _bullets)
    {
        bullet->Update();
    }
}

void Cannon::Render(HDC hdc)
{
    _barrel->Render(hdc);
    _body->Render(hdc);

    for (auto bullet : _bullets)
    {
        bullet->Render(hdc);
    }
}

void Cannon::Move()
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        _body->_center._x += 1.0f;
        _isActionComplete = true;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        _body->_center._x -= 1.0f;
        _isActionComplete = true;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        _angle -= 0.01f;
        _isActionComplete = true;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        _angle += 0.01f;
        _isActionComplete = true;
    }

    _barrel->SetAngle(_angle);
    _barrel->SetStart(_body->_center);
}

void Cannon::Fire()
{
    if (GetAsyncKeyState(VK_SPACE) & 0x0001)
    {
        auto iter = std::find_if(_bullets.begin(), _bullets.end(),
            [](shared_ptr<Bullet> bullet) -> bool
            {
                return !bullet->IsActive();
            });

        if (iter != _bullets.end())
        {
            (*iter)->Fire(_barrel->GetEndPos(), _barrel->GetDirection());
            _isActionComplete = true;
        }
    }
}

bool Cannon::IsActionComplete() const
{
    return _isActionComplete;
}

void Cannon::TakeDamage(int amount)
{
    _curHp -= amount;
    if (_curHp < 0)
        _curHp = 0;
}