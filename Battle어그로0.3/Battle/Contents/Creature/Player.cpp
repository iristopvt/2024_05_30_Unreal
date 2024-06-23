#include "pch.h"
#include "Player.h"

Player::Player(string name, int hp, int atk, int mp)
// : Creature()
	: Creature(name, hp, atk, mp)
	, _exp(0), Aggro(0)
{
}

Player::~Player()
{
}

//void Player::Die()
//{
//	Creature::Die(); // 기본 메시지 출력
//	cout << "플레이어 " << _name << "가(이) 죽었습니다!" << endl;
//}

//void Player::Angnum()
//{
//	if (_Ang > 0  )
//	{
//
//	}
//
//
//}
