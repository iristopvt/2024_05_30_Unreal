#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

// Heap sort
// 힙트리에 하나씩 다 집어넣고 하나씩 꺼낸다.

// 평균 시간 복잡도 : N * logN
// 최악의 경우 : N^2

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	// 처음들어왔을 떄는 제일 작게 쪼개져있는 상태
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
	// 왼쪽에 있던 원소들이 temp에 다 복사가 되었다.
	// right 배열이 남아있었다.

	if (leftIndex > mid)
	{
		while (rigthIndex <= right)
		{
			temp.push_back(v[rigthIndex]);
			rigthIndex++;
		}
	}
	// 오른쪽에 있던 원소들이 temp에 다 복사가 되었다.
	// left 배열이 남아있다.
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
	Mergsort(v, left, mid); // 왼쪽 정렬
	Mergsort(v, mid + 1, right); // 오른쪽 정렬

	// Conquer 
	MergeResult(v, left, mid, right);

}

int main()
{
	vector<int> v = { 55,30,15,100,1,5,70 };
	
	Mergsort(v, 0, v.size() - 1);
	// N * logN 만큼의 시간복잡도를 가지는 정렬 3인방
	//MergeResult
	//std::stable_sort(v.begin(), v.end());
	//std::partial_sort(v.begin(), v.end()+3,v.end());

	return 0;
}