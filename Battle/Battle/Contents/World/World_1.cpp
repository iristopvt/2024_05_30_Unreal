#include "pch.h"
#include "World_1.h"

World_1::World_1()
: _player1(nullptr)
, _player2(nullptr)
{
	CreatePlayer();

	// player2 생성
	//_player2 = new Knight("player2", 100, 5);
	_player2 = make_shared<Creature>("Player2", 100, 5);

}

World_1::~World_1()
{
	_player1 =make_shared< Creature>();
	_player2 =make_shared< Creature>();
}

void World_1::CreatePlayer()
{
	int input = 0;
	cin >> input;

	string name = "Hanil";

	switch (input)
	{
	case 1:
		//_player1 = new Knight(name, 5000, 30);
		shared_ptr<Creature> _player1 = make_shared<Knight>(name, 5000, 30);
		shared_ptr<Creature> _player1 = std::make_shared<Knight>(name, 5000, 30);
		break;
	case 2:
		//_player1 = new Archer(name , 1000, 60);
		//_player1 = make_shared<Archer>(name, 5000, 30);
		shared_ptr<Creature> _player1 = std::make_shared<Archer>(name, 5000, 30);
		break;
	default:
		break;
	}
}

void World_1::Battle()
{
	_player1->Attack(_player2);
	_player2->Attack(_player1);
}

bool World_1::End()
{
	return _player1->IsDead() || _player2->IsDead();
}
