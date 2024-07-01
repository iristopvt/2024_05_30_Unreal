#pragma once
class Line2scene : public Scene
{
public:
	Line2scene();
	~Line2scene();


	// Scene을(를) 통해 상속됨
	void Update() override;

	void Render(HDC hdc) override;

	

public:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;

	shared_ptr<CircleCollider> _circle;

};

