#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
//class DisJointSet
//{
//public:
//    DisJointSet(int n)
//    {
//        _parent = vector<int>(n, 0);
//        _rank = vector<int>(n, 1);
//        for (int i = 0; i < n; i++)
//        {
//            _parent[i] = i;
//        }
//    }
//    int FindLeader(int u)
//    {
//        if (u == _parent[u])
//            return u;
//
//        int parent = _parent[u];
//        return FindLeader(parent);
//    }
//
//
//    // [0] [2]    [5]
//    // [1] 
//    // [3]
//    void Merge(int u, int v)
//    {
//        int uLeader = FindLeader(u);
//        int vLeader = FindLeader(v);
//
//        if (uLeader == vLeader)
//            return;
//
//        if (_rank[uLeader] > _rank[vLeader])
//        {
//            std::swap(uLeader, vLeader);
//
//        }
//        _parent[uLeader] = vLeader;
//
//        if (_rank[uLeader] == _rank[vLeader])
//            _rank[vLeader]++;
//
//    }
//
//private:
//    vector<int> _parent;
//    vector<int> _rank;
//
//};
//struct Edge
//{
//    Edge(int u, int v, int cost) :u(u), v(v), cost(cost) {}
//
//    int u;
//    int v;
//    int cost;
//
//}
//vector<Edge> edges;
//
//
//
//void CreateEdges(vector<vector<int>>& cost)
//{
//    for (auto cost : costs)
//    {
//        int u = cost[0];
//        int v = cost[1];
//        int c = cost[2];
//
//        Edge edge = Edge(u, v, c);
//        edges.push_back(edge);
//    }
//}
//
//vector<Edge> Kruskal(int n)
//{
//    vector<Edge> result;
//
//    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)->bool {
//        if (a.cost < b.cost)
//            return true;
//        return false;
//        });
//
//    DisJointSet set(n);
//
//    for (auto edge : edges)
//    {
//        int u = edge.u;
//        int v = edge.v;
//
//        if (set.FindLeader(u) == set.FindLeader(v))
//            continue;
//
//        set.Merge(u, v);
//        result.push_back(edge);
//    }
//
//    return result;
//}
//
//int solution(int n, vector<vector<int>> costs) {
//    int answer = 0;
//    CreateEdges(costs);
//        auto result = Kruskal(n);
//
//    for (auto edge : result)
//    {
//        answer += edge.cost;
//    }
//    //for(int i = 0; i < costs.size(); i++)
//
//
//
//    return answer;
//}

#include<vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Vector2
{
    Vector2() {}
    Vector2(int y, int x) : y(y), x(x) {}

    int y = 0;
    int x = 0;

    bool operator==(const Vector2& other)
    {
        if (y != other.y) return false;
        if (x != other.x) return false;

        return true;
    }
   /* Vector2 operator+(const Vector2& other)
    {
        Vector2 result = *this;
        *this = (*this) + Vector2(1, 1);

        return result;
    }*/
};

Vector2 dir[4] =
{
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

vector<vector<bool>> discovered;
vector<vector<Vector2>> parent;
vector<vector<int>> adjacent;
int n, m = 0;

bool Cango(Vector2 pos)
{
    if (pos.x < 0 || pos.x >= n)
        return false;
    if (pos.y < 0 || pos.y >= m)
        return false;

    if (adjacent[pos.y][pos.x] == 0)
        return false;

    return true;
}

void BFS(Vector2 start)
{
    discovered[start.y][start.x] = true;
    parent[start.y][start.x] = start;

    queue<Vector2> q;
    q.push(start);

    while (true)
    {
        if (q.empty()) break;

        Vector2 here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
           // Vector2 there = here + dir[i];
           Vector2 there;
           there.y = here.y + dir[i].y;
           there.x = here.x + dir[i].x;

           if (!Cango(there))
               continue;
           if (discovered[there.y][there.x] == true)
               continue;

           q.push(there);
           discovered[there.y][there.x] = true;
           parent[there.y][there.x] = here;

        }

    }


 /*   discovered[start.y][start.x] = true;
    parent[start.y][start.x] = start;

    queue<Vector2> q;
    q.push(start);

    while (true)
    {
        if (q.empty())
            break;

        Vector2 here = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            Vector2 there;
            there.y = here.y + dir[i].y;
            there.x = here.x + dir[i].x;

            if (!Cango(there))
                continue;
            if (discovered[there.y][there.x])
                continue;

            q.push(there);
            discovered[there.y][there.x] = true;
            parent[there.y][there.x] = here;
        }
    }*/
}

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    m = maps.size();
    n = maps[0].size();

    discovered = vector<vector<bool>>(m, vector<bool>(n, false));
    parent = vector<vector<Vector2>>(m, vector<Vector2>(n, { -1,-1 }));
    adjacent = maps;

    BFS({ 0,0 });

    Vector2 end = { m - 1, n - 1 };
    while (true)
    {
        if (parent[end.y][end.x] == Vector2(-1, -1))
            return -1;

        if (parent[end.y][end.x] == end)
            break;

        end = parent[end.y][end.x];
        answer++;
    }

    return answer;
}




int answer = 0;
//vector<bool> visited;
vector<int> arr;
int maTarget = 0;

//void DFS(int sum,int index)
//{
//    // 재귀함수의 기저사항
//    // -> 마지막 반환될 예외 처리
//
//    if (index >= arr.size())
//    {
//        if (sum == maTarget)
//        {
//            answer++;
//        }
//        return;
//
//    }
//    DFS(index + 1, sum + arr[index]);
//    DFS(index + 1, sum - arr[index]);
//
//    //for (int i = 0; i < numbers.size(); i++)
//    //{
//    //   // int total = 0;
//    // 
//    //}
//
//    //for (int i = 0; i < numbers.size(); i++)
//    //{
//    //    for (int i = 0; i =< target; i++)
//    //    {
//
//    //    }
//    //    if ()
//    //    {
//    //        total += numbers[i];
//    //    }
//    //    else
//    //    {
//    //        total -= numbers[i];
//    //    }
//
//
//    //}
// 
//}
//
//int solution(vector<int> numbers, int target) {
//
//    arr = numbers;
//    maTarget = target;
//
//    DFS(0,0)
//
//    return answer;
//}

//#include <string>
//#include <vector>
//
//using namespace std;
//vector<bool> visited;
//vector<string> baba = { "ata","ye","woo","ma" };
//
//
//void DFS(vector<string>& babbling,int str)
//{
//	visited[str] = true;
//
//	for (int i = 0; i < babbling.size(); i++)
//	{
//		for (int j = 0; j < baba.size(); j++)
//		{
//			if (babbling[i] == false)
//				continue;
//			if (visited[i] == true)
//				continue;
//		}
//
//}
//
//int solution(vector<string> babbling) 
//{
//    int answer = 0;
//
//
//
//
//
//
//    return answer;
//}

//for (int i = 0; i < babbling.size(); i++)
//{
//	for (int j = 0; j < baba.size(); j++)
//	{
//		if (babbling.g == baba)
//		{
//			++answer;
//		}
//	}
//
//
//}