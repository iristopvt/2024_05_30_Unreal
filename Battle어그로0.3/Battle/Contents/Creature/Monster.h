#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk,int mp);
	virtual ~Monster();

	virtual void Attack(Creature* other) override;
	//void MutilAtack(Creature* other);
};

