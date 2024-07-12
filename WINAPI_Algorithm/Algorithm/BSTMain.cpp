#include "Binarysearchtree.h"
#include <unordered_map>
#include <map>

// �ؽ� ���̺� : �޸𸮸� �ְ� Ž���ð��� ���Ѵ�.
// Ž�� : ��� ... �ؽ��浹�� ���� ü�̴׿� ���� �޶��� �� �ִ�.
// ���� : ���
// �浹, ü�̴�

// �ڰ���������Ž��Ʈ��
// Ž�� :logN
// ���� :logN

// �ؽ����̺� vs �ڰ���������Ž��Ʈ��
// �ؽ��Լ� �� �浹�� ���� �Ͼ ���..... �ڰ���������Ž��Ʈ�� ��
// �浹�� ���� ���..... �ؽ����̺� �� 


int main()
{

#pragma region BST
	Binarysearchtree bst;
	bst.Insert(50);
	bst.Insert(40);
	bst.Insert(70);
	bst.Insert(30);
	bst.Insert(45);
	
	bst.Printree(bst._root);
	cout << "--------" << endl;
	//bst.search(bst._root, 40);
	cout << bst.search(bst._root, 30)->key << endl;
	auto searchNode = bst.search(bst._root, 100);

	if (searchNode !=nullptr)
	{
		cout << " �ش� ��带 ã�ҽ��ϴ�" << endl;
		cout << searchNode->key << endl;
	}
	else
	{
		cout << "�ش� ��尡 �����ϴ�" << endl;
	}

	auto minNode = bst.Min(bst._root);
	cout << minNode->key << endl;

	auto maxNode = bst.Max(bst._root);
	cout << maxNode->key << endl;

	cout << "--------" << endl;

	auto PreviousNode = bst.Previous(bst._root);
	cout << PreviousNode->key << endl;

	bst.Min(bst._root);
#pragma endregion 

	unordered_map<int, int> um;

	um[5] = 1;


	return 0;
}