#pragma once
class Block : public RectCollider
{
public:
	enum class BlockType
	{
		ABLE, // 0
		DISABLE, // 1
		PLAYER_POS // 2
	};

	Block();
	~Block();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	void SetPosition(Vector2 pos);

	void SetBlockType(BlockType type);
	BlockType GetBlockType() { return _type; }
	//bool IsActive() { return _type == BlockType::ABLE; } 
	bool IsActive() const; // 활성화 상태 확인 함수
	void SetActive(bool active); // 활성화 상태 설정 함수


private:
	BlockType _type = BlockType::ABLE;

	bool _isActive = true; // 블록의 활성화 상태를 나타내는 변수
	
	vector<HBRUSH> _brushes;


};

