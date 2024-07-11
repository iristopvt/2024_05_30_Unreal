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

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// ó�������� ���� ���� �۰� �ɰ����ִ� ����
	int leftIndex = left;
	int rigthIndex = mid + 1;
	
	// 55 / 30
	// left = 0
	// right = 1

	// leftIndex = 0
	// rightIndex 1
	// mid 0
	vector<int> temp(v.size());

	while (true)
	{
		
		if (leftIndex > mid || rigthIndex > right)
			break;

		if (v[leftIndex] <= v[rigthIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rigthIndex]);
			rigthIndex++;
			// temp : 30
			// leftIndex : 0
			// rightIndex : 2
		}

	}
	// ���ʿ� �ִ� ���ҵ��� temp�� �� ���簡 �Ǿ���.
	// right �迭�� �����־���.

	if (leftIndex > mid)
	{
		while (rigthIndex <= right)
		{
			temp.push_back(v[rigthIndex]);
			rigthIndex++;
		}
	}
	// �����ʿ� �ִ� ���ҵ��� temp�� �� ���簡 �Ǿ���.
	// left �迭�� �����ִ�.
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
				leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + 1] = temp[1];
	}


}

void Mergsort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	// Divide
	Mergsort(v, left, mid); // ���� ����
	Mergsort(v, mid + 1, right); // ������ ����

	// Conquer 
	MergeResult(v, left, mid, right);

}

int main()
{
	vector<int> v = { 55,30,15,100,1,5,70 };
	
	Mergsort(v, 0, v.size() - 1);
	// N * logN ��ŭ�� �ð����⵵�� ������ ���� 3�ι�
	//MergeResult
	//std::stable_sort(v.begin(), v.end());
	//std::partial_sort(v.begin(), v.end()+3,v.end());

	return 0;
}