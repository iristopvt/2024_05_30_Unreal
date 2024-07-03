#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetStartI(Vector2 start); // 배럴 시작  위치 설정
	void SetAngle(float angle); // 배럴 각도 설정

	Vector2 GetEndPos() { return _line->_end; }  // 끝점
	Vector2 GetDirection() { return _direction; } //방향
	

private:
	shared_ptr<Line> _line;

	float _barrelLength = 100.0f; //배럴 길이
	Vector2 _direction = Vector2(1, 0); // 배럴 방향 

};

