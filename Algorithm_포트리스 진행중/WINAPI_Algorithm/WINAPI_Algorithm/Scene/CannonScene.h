#pragma once

class Cannon;
class CannonScene : public Scene
{
public:
	CannonScene();
	~CannonScene();

	int _Turn ;
	bool _isTurnEnd;

	//bool Mov
	// Scene을(를) 통해 상속됨
	void Update() override;
	void Render(HDC hdc) override;

	void EndTurn();  // 턴 종료 메서드
	bool CheckTurnEndCondition();  // 턴 종료 조건 확인

private:
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;
};

