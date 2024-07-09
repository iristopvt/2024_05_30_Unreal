#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <concurrent_priority_queue.h>


using namespace std;

class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}
	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}


	// [0] [2]    [5]
	// [1] 
	// [3]
	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			std::swap(uLeader, vLeader);

		}
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;

	}

private:
	vector<int> _parent;
	vector<int> _rank;

};

// 크루스칼? 프림 ? 알고리즘 ?
// 
// MST : (Minimum Spanning Tree)
// 간선들의 가중치의 합이 최소인 트리 (노드,간선,가중치가 주어졌을때 가중치를 고려하여 최소 비용
// 얻고자 하는것
// 특징
// - 간섭의 가중치의 합이 최소 // 최소 신장 트리
// - n개의 정점을 가지는 그래프는 반드시 n-1개의 간선을 사용
// - 
// 
// Disjoint set
// 그룹이 있따 ? 각 그룹에 공통된 요소가 없다 오직 하나의 root? 





struct  Edge
{
	int u; // 시작점
	int v; // 끝점 

	int length; // 길이 
};

vector<vector<int>> adjacent;
vector<Edge> edges;

void CreateGraph_AdjacentMatrix()
{
	//    0  1  2  3  4  5  6
	// 0  T  T  T  F  T  F  F
	// 1  T  T  F  F  F  F  F
	// 2  T  F  T  T  T  T  F
	// 3  F  F  T  T  F  F  F
	// 4  T  F  T  F  T  F  T
	// 5  F  F  T  F  F  T  T
	// 6  F  F  F  F  T  T  T

	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 3;
	adjacent[0][2] = 2;
	adjacent[0][4] = 10;

	adjacent[1][0] = 3;
	adjacent[1][1] = 0;

	adjacent[2][0] = 2;
	adjacent[2][2] = 0;
	adjacent[2][3] = 7;
	adjacent[2][4] = 3;
	adjacent[2][5] = 5;

	adjacent[3][2] = 7;
	adjacent[3][3] = 0;

	adjacent[4][0] = 10;
	adjacent[4][2] = 3;
	adjacent[4][4] = 0;
	adjacent[4][6] = 4;

	adjacent[5][2] = 5;
	adjacent[5][5] = 0;
	adjacent[5][6] = 1;

	adjacent[6][4] = 4;
	adjacent[6][6] = 0;
	adjacent[6][5] = 1;

}

void CreateEdges()
{
	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent.size(); v++) 
		{
			if (u >= v) continue;
			
			if (adjacent[u][v] == 1)
				continue;

			Edge edge;
			edge.u = u;
			edge.v = v;
			edge.length = adjacent[u][v];

			edges.push_back(edge);
		}
	}
}

vector<Edge> Kruskal()
{
	vector<Edge> result;

	std::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2)-> bool
		{
			if (e1.length < e2.length)
				return true;
			return false;
		});

	DisJointSet set(adjacent.size());

	for (auto& edge : edges)
	{
		int u = edge.u;
		int v = edge.v;

		if (set.FindLeader(u) == set.FindLeader(v))
			continue;

		set.Merge(u, v);
		result.push_back(edge);
	}
	return result;
}

int main()
{
	CreateGraph_AdjacentMatrix();
	CreateEdges();

	vector<Edge> mst = Kruskal();

	for (auto& edge : mst)
	{
		cout << edge.u << " ~ " << edge.v << "........길이는 " << edge.length << endl;
	}

	return 0;
}