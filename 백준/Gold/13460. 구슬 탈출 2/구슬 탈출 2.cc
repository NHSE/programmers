#include <iostream>
#include <queue>
using namespace std;

char map[10][11];

struct INFO
{
	int rx, ry, bx, by, count;
};

INFO start;

int bfs()
{
	int ret = -1;
    bool visited[10][10][10][10] = { false, };
	queue<INFO> q;

	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };

	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = true;
	while (!q.empty())
	{
		INFO info = q.front();
		q.pop();

		if (info.count > 10)	break;

		if (map[info.ry][info.rx] == 'O' && map[info.by][info.bx] != 'O')
		{
			ret = info.count;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_ry = info.ry;
			int next_rx = info.rx;

			int next_by = info.by;
			int next_bx = info.bx;

			while (1)
			{
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
				{
					next_ry += dy[i];
					next_rx += dx[i];
				}
				else
				{
					if (map[next_ry][next_rx] == '#')
					{
						next_ry -= dy[i];
						next_rx -= dx[i];
					}
					break;
				}
			}

			while (1)
			{
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
				{
					next_by += dy[i];
					next_bx += dx[i];
				}
				else
				{
					if (map[next_by][next_bx] == '#')
					{
						next_by -= dy[i];
						next_bx -= dx[i];
					}
					break;
				}
			}
			if (next_ry == next_by && next_rx == next_bx)
			{
				if (map[next_ry][next_rx] != 'O')
				{
					int r = abs(next_ry - info.ry) + abs(next_rx - info.rx);
					int b = abs(next_by - info.by) + abs(next_bx - info.bx);
					if (r > b)
					{
						next_ry -= dy[i];
						next_rx -= dx[i];
					}
					else
					{
						next_by -= dy[i];
						next_bx -= dx[i];
					}
				}
			}
			if (!visited[next_ry][next_rx][next_by][next_bx])
			{
				visited[next_ry][next_rx][next_by][next_bx] = true;
				INFO next;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.count = info.count + 1;
				q.push(next);
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				start.rx = j;
				start.ry = i;
			}
			else if (map[i][j] == 'B')
			{
				start.bx = j;
				start.by = i;
			}
		}
	}
	start.count = 0;
	cout << bfs();
	return 0;
}