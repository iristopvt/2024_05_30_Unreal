#pragma once
class Mage : public Player
{
public:
	Mage(string name, int hp, int atk,int mp);
	virtual ~Mage();

	virtual void Attack(Creature* other) override;
private:

};

