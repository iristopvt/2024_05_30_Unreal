#pragma once

class Bar;
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;


private:

	shared_ptr<Bar> _bar;
	shared_ptr<class Ball> _ball;
	shared_ptr<class Brick> _brick;



};

