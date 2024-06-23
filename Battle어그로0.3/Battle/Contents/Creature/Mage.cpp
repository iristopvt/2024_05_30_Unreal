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
		cout << "마나가 부족하여 공격 대신 마나를 50만큼 회복합니다" << endl;
		_mp += 50;

	}
}
