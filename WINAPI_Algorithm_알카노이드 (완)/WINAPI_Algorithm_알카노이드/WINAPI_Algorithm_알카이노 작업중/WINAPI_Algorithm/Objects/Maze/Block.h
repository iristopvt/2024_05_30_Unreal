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
	bool IsActive() const; // Ȱ��ȭ ���� Ȯ�� �Լ�
	void SetActive(bool active); // Ȱ��ȭ ���� ���� �Լ�


private:
	BlockType _type = BlockType::ABLE;

	bool _isActive = true; // ����� Ȱ��ȭ ���¸� ��Ÿ���� ����
	
	vector<HBRUSH> _brushes;


};

