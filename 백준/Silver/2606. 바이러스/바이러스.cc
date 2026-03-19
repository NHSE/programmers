#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>>	v;

void BFS()
{
	queue<int> q;
	q.push(1);
	bool visited[100] = { false, };
	visited[1] = true;

	int cnt = -1;

	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		cnt++;
		for (int i = 0; i < v[a].size(); i++)
		{
			if (!visited[v[a][i]])
			{
				visited[v[a][i]] = true;
				q.push(v[a][i]);
			}
		}
	}

	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N;
	cin >> M;

	v.resize(N+1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS();
}