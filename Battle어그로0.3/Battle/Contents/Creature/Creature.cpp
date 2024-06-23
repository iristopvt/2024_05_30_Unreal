#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int atk,int mp)
: _name(name), _curHp(hp), _atk(atk), _maxHp(hp),_mp(mp)
{
}

Creature::~Creature()
{
}

void Creature::PrintInfo()
{
	cout << "---- 정보 ----" << endl;
	cout << "이름 : " << _name << endl;
	cout << "HP : " << _curHp << endl;
	cout << "ATK : " << _atk << endl;
	cout << "---------------" << endl;
}

void Creature::PreAttack(Creature* other)
{
	cout << _name << "이 " << other->_name << "에게 공격을 시도합니다." << endl;
}

void Creature::TakeDamage(int amount)
{
	_curHp -= amount;

	if (_curHp < 0)
		_curHp = 0;

	PrintInfo();
}

//void Creature::Die()
//{
//	cout << _name << "가(이) 죽었습니다!" << endl;
//}
