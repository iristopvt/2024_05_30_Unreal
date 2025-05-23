#include <iostream>

using namespace std;

// Singleton
// 1. �������� ������ �����ؾ��Ѵ�.
// 2. ���α׷��� �� �ϳ��� �����ؾ��Ѵ�.
// 3. �����Ҵ�Ǿ���Ѵ�.

class SoundManager
{
private:
	SoundManager() {}
	~SoundManager() {}

public:
	// private ������ �� �ִ� ��� : public ����Լ�
	//
	static void Create()
	{
		if(instance == nullptr)
			instance = new SoundManager();
	}

	static void Delete()
	{
		if (instance != nullptr)
			delete instance;
	}

	static SoundManager* GetInstance()
	{
		if (instance != nullptr)
			return instance;
		return nullptr;
	}

	void PrintAllSound()
	{
		cout << _warriorSound << endl;
		cout << _archerSound << endl;
	}

	void PrintWarriorSound()
	{
		cout << _warriorSound << endl;
	}

private:
	static SoundManager* instance;
	string _warriorSound = "������ ����!";
	string _archerSound = "���� ����!";
};

SoundManager* SoundManager::instance = nullptr;

class Warrior
{
public:
	Warrior() { SoundManager::GetInstance()->PrintWarriorSound(); }
};

int main()
{
	SoundManager::Create();
	
	Warrior* warrior = new Warrior();

	delete warrior;

	SoundManager::Delete();

	return 0;
}