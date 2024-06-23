#include "pch.h"
#include "Monster.h"

Monster::Monster(string name, int hp, int atk,int mp)
: Creature(name, hp, atk,mp)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Creature* other)
{
	this->Creature::PreAttack(other);
	other->TakeDamage(_atk);

}

//void Monster::MutilAtack(Creature* other)
//{
//	//Player* player;
//	//
//	//for (int i = 1; i < 5; i++)
//	//{
//	//	this->Creature::PreAttack(other);
//	//	if (player->_Ang >= 40) // 이러면 한명의 어그로 수치로 판단해서 4번공격함 
//	//		other->TakeDamage(_atk); // 한번 때리면 때린 상대를 제외해야할듯 
//	//	else if (player->_Ang >= 35)
//	//		other->TakeDamage(_atk);
//	//	else if (player->_Ang >= 15)
//	//		other->TakeDamage(_atk);
//
//	//	//else if (player->_Ang > 3)//other->
//
//	//}
//
//
//}
