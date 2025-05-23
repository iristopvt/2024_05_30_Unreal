#pragma once

// �߻�Ŭ����
class Creature
{
public:
	Creature();
	Creature(int hp, int mp, int attack);
	virtual ~Creature();

	void PrintCreature();
	virtual void Attack(Creature* p) abstract;
	void TakeDamage(int amount);

	// stat�� �缳���ϴ� �Լ�
	void SetStat(int hp, int mp, int attack);
	void SetName(const string& name);

	bool IsDead() { return _hp <= 0; }

	// get set
	void SetHp(int hp) { _hp = hp; }
	const int& GetHP() { return _hp; }

protected:
	int _hp;
	int _mp;
	int _attack;
	string _name;
};

