#pragma once
class Goblin : public Creature
{
public:
	Goblin();
	Goblin(int hp, int mp, int attack);
	virtual ~Goblin();

	// �Լ� �������̵�
	virtual void Attack(Creature* p) override;
private:

};

