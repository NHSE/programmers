#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[8][8];
int copy_map[8][8];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int answer = 0;

queue<pair<int, int>> q;

void DFS(int x, int y, int wall_cnt);
void BFS();

int Count();

int main()
{
	cin >> N >> M;

	for(int y=0; y<N; y++)
	{
		for(int x=0; x<M; x++)
		{
			cin >> map[x][y];
			if(map[x][y] == 2)
			{
				q.push({x, y});
			}
		}
	}

	DFS(0,0,0);

	cout << answer;
}

void DFS(int x, int y, int wall_cnt)
{
	if(wall_cnt == 3)
	{
		memcpy(copy_map, map, sizeof(map));
		BFS();
		if(answer < Count())
		{
			answer = Count();
		}
	}
	else
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				if(map[j][i] == 0)
				{
					map[j][i] = 1;
					DFS(j, i, wall_cnt+1);
					map[j][i] = 0;
				}
			}
		}
	}
}

void BFS()
{
	queue<pair<int, int>> q_temp = q;
	while(!q_temp.empty())
	{
		int now[2];
		now[0] = q_temp.front().first;
		now[1] = q_temp.front().second;
		q_temp.pop();
		for(int i=0; i<4; i++)
		{
			int temp_x = now[0] + dx[i];
			int temp_y = now[1] + dy[i];
			if(temp_x < 0 || temp_y < 0 || temp_x >= M || temp_y >= N)
				continue;
			if(copy_map[temp_x][temp_y] == 0)
			{
				copy_map[temp_x][temp_y] = 2;
				q_temp.push({temp_x, temp_y});
			}
		}
	}
}

int Count()
{
	int count = 0;
	for(int y=0; y<N; y++)
	{
		for(int x=0; x<M; x++)
		{
			if(copy_map[x][y] == 0)
			{
				count++;
			}
		}
	}
	return count;
}