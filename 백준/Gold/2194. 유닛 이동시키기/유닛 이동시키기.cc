/*
* 유닛은 상하좌우의 네 방향으로만 움직일 수 있다. 
단, 유닛의 일부분이 장애물이 설치된 부분(위의 예에서 색이 칠해진 부분)을 지날 경우, 
위의 예에서는 시작 위치에서 위로 이동하는 경우는 허용되지 않는다. 
위의 예는 유닛을 오른쪽으로 세 칸, 위쪽으로 세 칸 움직이면 목적지에 도달할 수 있고, 
이 경우가 가장 적은 이동 회수를 거치는 경우이다. 이동하는 도중에 유닛이 맵 밖으로 나가는 경우는 허용되지 않는다.

첫째 줄에 다섯 개의 정수 N, M(1 ≤ N, M ≤ 500), A, B(1 ≤ A, B ≤ 10), K(0 ≤ K ≤ 100,000)가 주어진다. 
다음 K개의 줄에는 장애물이 설치된 위치(행 번호, 열 번호)가 주어진다. 
그 다음 줄에는 시작점의 위치와 도착점의 위치가 주어진다. 
시작점의 위치와 도착점의 위치는 제일 왼쪽 제일 위의 한 점만 주어진다. 
시작점의 위치와 도착점의 위치는 같지 않다.

첫째 줄에 답을 출력한다. 이동이 불가능한 경우에는 -1을 출력한다.
*/
#include <iostream>
#include <queue>

using namespace std;

struct Data
{
	int x, y, depth;
};

bool map[501][501] = { false, };
bool visited[501][501] = { false, };

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M, A, B, K;

int sx, sy;
int ex, ey;

int answer = 1e9;

bool IsRange(int x, int y)
{
	for (int i = x; i < x + A; i++)
	{
		for (int j = y; j < y + B; j++)
		{
			if (i <= 0 || i > N || j <= 0 || j > M)
				return false;
		}
	}
	return true;
}

bool Cango(int x, int y)
{
	for (int i = x; i < x + A; i++)
	{
		for (int j = y; j < y + B; j++)
		{
			if (map[i][j])
				return false;
		}
	}
	return true;
}

bool BFS(int x, int y, int depth)
{
	queue<Data> q;
	q.push({ x, y, depth });
	visited[x][y] = true;

	while (!q.empty())
	{
		Data data = q.front();
		q.pop();

		if (data.x == ex && data.y == ey)
		{
			answer = data.depth;
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = data.x + dx[i];
			int ny = data.y + dy[i];

			if (!IsRange(nx, ny))	continue;
			if (!Cango(nx, ny))	continue;

			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx, ny, data.depth + 1 });
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> A >> B >> K;

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = true; // 장애물
	}

	cin >> sx >> sy;
	cin >> ex >> ey;

	if (!BFS(sx, sy, 0))
		cout << "-1";
	else
		cout << answer;

}