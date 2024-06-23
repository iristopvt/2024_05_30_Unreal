#pragma once
class Creature
{
public:
	Creature(string name, int hp, int atk,int mp);
	virtual ~Creature();

	// 멤버함수 : 기능
	void PrintInfo();
	void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // 순수가상함수
	void TakeDamage(int amount);

	bool IsDead() { return _curHp <= 0; }
private:
	//void Die();
protected: // 멤버변수: 속성
	string _name;
	int _curHp;
	int _maxHp;
	int _atk;
	int _mp;
};

