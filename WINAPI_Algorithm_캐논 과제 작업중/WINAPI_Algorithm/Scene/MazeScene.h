#pragma once
class MazeScene : public Scene
{
public:
	MazeScene();
	~MazeScene();

	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

private:
	shared_ptr<class Maze> _maze;
	shared_ptr<class Player> _mazeRunner;

};

