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
	cout << "---- ���� ----" << endl;
	cout << "�̸� : " << _name << endl;
	cout << "HP : " << _curHp << endl;
	cout << "ATK : " << _atk << endl;
	cout << "---------------" << endl;
}

void Creature::PreAttack(Creature* other)
{
	cout << _name << "�� " << other->_name << "���� ������ �õ��մϴ�." << endl;
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
//	cout << _name << "��(��) �׾����ϴ�!" << endl;
//}
