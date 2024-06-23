#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int atk, int mp);
	virtual ~Player();

	//virtual void Angnum();

	int Aggro; //플레이어가 공격할때마다 어그로 수치가 쌓이게 설정 
	//void Die() override;
protected:
	int _exp;
};

