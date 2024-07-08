#pragma once
#include "Objects/Maze/Block.h"


class Brick //: public RectCollider

#define MAXCOUNT_X 8
#define MAXCOUNT_Y 3
{
public:
	Brick();
	~Brick();

	void Update();
	void Render(HDC hdc);

	void Ballaway(shared_ptr<class Ball> ball);
	bool IsActive() { return _BrisActive; }
	

private:
	vector<vector<shared_ptr<Block>>> _blocks;
	shared_ptr< Brick> _brick;
	bool _BrisActive = false;


};

