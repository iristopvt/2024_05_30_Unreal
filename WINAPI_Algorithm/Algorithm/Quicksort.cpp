#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Heap sort
// ��Ʈ���� �ϳ��� �� ����ְ� �ϳ��� ������.

// ��� �ð� ���⵵ : N * logN
// �־��� ��� : N^2

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];
	int lowIndex = left + 1;
	int highIndex = right;
	while (true)
	{
		if (lowIndex > highIndex)
			break;

		// lowIndex�� �׻� pivot���� �۾ƾ��Ѵ�.
		// ������ ���� Index�� Ȯ���Ѵ�
		while (lowIndex <= right && pivot >= v[lowIndex])
		{
			lowIndex++;
		} 

		//highIndex�� �׻� pivot���� Ŀ���Ѵ�.
		// ũ�� ���� Index�� Ȯ���Ѵ�
		while (highIndex >= left + 1 && pivot <= v[highIndex])
		{
			highIndex--;
		}
		if (lowIndex < highIndex)
			std::swap(v[lowIndex], v[highIndex]);

	}

	return highIndex;
}

void Quicksort(vector<int>& v, int left, int right)
{
	// ��������
	if (left > right)
		return;

	int pivotIndex = Partition(v, left, right);
	cout << left << " ~ " << pivotIndex - 1 << endl;
	Quicksort(v, left, pivotIndex -1);
	Quicksort(v, pivotIndex + 1, right);

}

int main()
{
	vector<int> v = { 55,30,15,100,1,5,70,30};
	Quicksort(v, 0, v.size() - 1);
	std::sort(v.begin(), v.end());
	

	return 0;
}