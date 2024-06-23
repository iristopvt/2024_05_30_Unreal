#include "pch.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int mp)
: Player(name, hp, atk,mp)
{
}

Knight::~Knight()
{
}

void Knight::Attack(Creature* other)
{
	this->Creature::PreAttack(other);
	float ratio = (float)_curHp / (float)_maxHp;

	if (ratio < 0.5f)
	{
		// 현재 체력이 50프로 미만
		other->TakeDamage(_atk * 2);
		Aggro += _atk*2;
	}
	else
	{
		other->TakeDamage(_atk);
		Aggro += _atk;
	}
}
