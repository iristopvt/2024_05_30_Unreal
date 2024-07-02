#pragma once
class Cannon
{
public:
    Cannon(Vector2 initialPosition);
    ~Cannon();

    void Update();
    void Render(HDC hdc);

    void Move();
    void Fire();

    bool IsActionComplete() const;

    shared_ptr<Collider> GetCollider() { return _body; }
    vector<shared_ptr<class Bullet>>& GetBullets() { return _bullets; }

    void TakeDamage(int amount);

private:
    shared_ptr<Collider> _body;
    shared_ptr<class Barrel> _barrel;
    vector<shared_ptr<class Bullet>> _bullets;
    int _curHp;
    int _maxHp;

    bool _isActionComplete;
    float _angle;
};

