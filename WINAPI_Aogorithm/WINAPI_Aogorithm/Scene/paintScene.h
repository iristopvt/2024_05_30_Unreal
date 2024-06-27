#pragma once
class PaintScene : public Scene
{
public:
	PaintScene();
	~PaintScene();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	//float _left = 0;
	//float _top = 0;
	//float _right = 50;
	//float _bottom = 50;

	shared_ptr<Rect> _rect;
	shared_ptr<Circle> _circle;
	// circle
};

