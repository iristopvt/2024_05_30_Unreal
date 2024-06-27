#pragma once
class World_1
{
public:
	World_1();
	~World_1();

	void CreatePlayer();

	void Battle();

	bool End();

private:
	Creature* _player1;
	Creature* _player2;
	shared_ptr<Creature> _player1;
	shared_ptr<Creature> _player2;
};

