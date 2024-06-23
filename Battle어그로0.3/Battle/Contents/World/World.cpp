#include "pch.h"	
#include "World.h"

World::World()
: _player(nullptr)
, _computer(nullptr)
, _hodgoblin(nullptr)
{
	//Input();
	Init();
}

World::~World()
{
	/*if(_player != nullptr)
		delete _player;
	if(_computer != nullptr)
		delete _computer;*/
	for (auto player : _players)
	{
		delete player;
	}
	if (_hodgoblin != nullptr)
	{
		delete _hodgoblin;
	}
}

void World::Init()
{
	//Input();
	Battle2();
}

bool World::End()
{
	/*if (_player->IsDead() || _computer->IsDead())
		return true;

	return false;*/
	/*if (_hodgoblin->IsDead())
		return true;

	for (auto player : _players)
	{
		if (!player->IsDead())
			return false;
	}

	return true;*/
	/*bool allPlayersDead = true;
	for (auto& player : _players)
	{
		if (!player->IsDead())
		{
			allPlayersDead = false;
			break;
		}
	}*/

	
	if (_hodgoblin->IsDead())
	{
		return true; // ���Ͱ� ������ ���� ����
	}

	bool allPlayersDead = true;
	for (auto& player : _players)
	{
		if (!player->IsDead())
		{
			allPlayersDead = false;
			break;
		}
	}

	return allPlayersDead;
}

void World::MultiAttack()
{
	sort(_players.begin(), _players.end(), [](Player* a, Player* b) {return a->Aggro > b->Aggro; });
	// ��׷� ���� ������ ����

	int Targets = min(4, static_cast<int>(_players.size())); // 4����� ����

	for (int i = 0; i < Targets; ++i)
	{
		Player* target = _players[i];
		if (!target->IsDead())
		{
			_hodgoblin->Attack(target);
		}
	}
	/*while (!_hodgoblin->IsDead()&& Targets > 0)
	{
		for (int i = 0; i < Targets; ++i)
		{
			Player* target = _players[i];
			_hodgoblin->Attack(target);

		}


	}*/
	RemovePlayers();
}

void World::SeletPlayer(int num, string name, Player** player)
{
	switch (num)
	{
	case PlayerType::NONE:
	{
		cout << "�ٽ� �Է����ּ���." << endl;
		break;
	}

	case PlayerType::KNIGHT:
	{
		*player = new Knight(name, 300, 15,0);
	}
	break;
	case PlayerType::ARCHER:
	{
		*player = new Archer(name, 200, 35,0);
	}
	break;
	case PlayerType::MAGE:
	{
		*player = new Mage(name, 150, 40, 50);
	}
	break;
	default:
	{
		cout << "�ٽ� �Է����ּ���." << endl;
		break;
	}
	break;
	}
}

void World::Input()
{
	int playerNum = 0;
	int cumNum = 0;
	string name;
	
	cout << "�̸��� �Է����ּ���" << endl;
	cin >> name;
	cout << "1~3������ Ŭ������ �Է����ּ���." << endl;

	cin >> playerNum;
	//cumNum = rand() % 2 + 1; // 1 ~ 2
	//SeletPlayer(playerNum, name, &_player);
	//SeletPlayer(cumNum, "computer", &_computer);

}

void World::Battle1()
{
	//_player->Attack(_computer);
	//_computer->Attack(_player);
	/*for (auto player : _players)
	{
		player->Attack(_hodgoblin);
	}
	MultiAttack();*/

	for (auto player : _players)
	{
		if (!player->IsDead())
		{
			player->Attack(_hodgoblin);
		}
	}

	RemovePlayers(); // ���� �� ���� �÷��̾� ����

	if (!_hodgoblin->IsDead())
	{
		MultiAttack();
	}

}

void World::Battle2()
{
	const int num = 10;
	_players.reserve(num); // reserve()�� ���� ������ ũ�⸦ �̸� �Ҵ�

	for (int i = 0; i < num; i++)
	{
		string name = "player" + to_string(i);
		int playernum = rand() % 3 + 1;
		Player* player = nullptr;

		SeletPlayer(playernum, name, &player); // player �����Ϳ� ������ �÷��̾ ����

		if (player != nullptr)
		{
			_players.push_back(player); // _players ���Ϳ� �÷��̾� �߰�
		}
	}
	_hodgoblin = new Monster("Hobgoblin", 1000, 200, 0);

	// ���� �ݺ�
	while (!End())
	{
		Battle1();
	}

	// ���� ���� �޽��� ���
	if (_hodgoblin->IsDead())
	{
		cout << "ȩ����� �׾����ϴ�. �������� �¸��߽��ϴ�!" << endl;
	}
	else
	{
		cout << "��� �÷��̾ �׾����ϴ�. �������� �й��߽��ϴ�." << endl;
	}
}

void World::RemovePlayers()
{
	auto it = _players.begin();
	while (it != _players.end())
	{
		if ((*it)->IsDead())
		{
			delete* it; // �޸� ����
			it = _players.erase(it); // ���Ϳ��� ����
		}
		else
		{
			++it;
		}
	}

}

	//MultiAttack();

//{
//	const int num = 10;
//	_players.reserve(num);
//
//	for (int i = 0; i < num; i++)
//	{
//		string name = "player" + to_string(i); 
//		int playernum = rand() % 3 + 1; 
//		Player* player = nullptr;
//
//		SeletPlayer(playernum, name, &_player);
//		if (player != nullptr)
//		{
//			_players.push_back(player);
//		}
//	}
//	
//
//	MultiAttack();
//
//
//}

//void World::MultiAttack()
//{
//	
//
//
//}
