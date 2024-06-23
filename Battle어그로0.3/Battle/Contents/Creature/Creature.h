#pragma once
class Creature
{
public:
	Creature(string name, int hp, int atk,int mp);
	virtual ~Creature();

	// ����Լ� : ���
	void PrintInfo();
	void PreAttack(Creature* other);
	virtual void Attack(Creature* other) abstract; // ���������Լ�
	void TakeDamage(int amount);

	bool IsDead() { return _curHp <= 0; }
private:
	//void Die();
protected: // �������: �Ӽ�
	string _name;
	int _curHp;
	int _maxHp;
	int _atk;
	int _mp;
};

