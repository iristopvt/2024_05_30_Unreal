#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int atk, int mp);
	virtual ~Player();

	//virtual void Angnum();

	int Aggro; //�÷��̾ �����Ҷ����� ��׷� ��ġ�� ���̰� ���� 
	//void Die() override;
protected:
	int _exp;
};

