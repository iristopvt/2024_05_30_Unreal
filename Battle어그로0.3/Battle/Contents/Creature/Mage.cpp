#include "pch.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk, int mp)
	: Player(name,hp,atk,mp)
{
}

Mage::~Mage()
{
}

void Mage::Attack(Creature* other)
{
	this->Creature::PreAttack(other);


	if (_mp > 5)
	{
		_mp -= 5;
		other->TakeDamage(_atk);
		Aggro += _atk;

	}
	else
	{
		cout << "������ �����Ͽ� ���� ��� ������ 50��ŭ ȸ���մϴ�" << endl;
		_mp += 50;

	}
}
