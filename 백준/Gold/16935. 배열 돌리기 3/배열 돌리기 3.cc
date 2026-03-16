#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[100][100];
int N, M, R;

void Command_1()
{
	int tmp_map[100][100];
	memcpy(tmp_map, map, sizeof(map));

	for (int c = 0; c < M; c++)
	{
		for (int r = 0; r < N; r++)
		{
			tmp_map[N - r - 1][c] = map[r][c];
		}
	}

	memcpy(map, tmp_map, sizeof(tmp_map));
}

void Command_2()
{
	int tmp_map[100][100];
	memcpy(tmp_map, map, sizeof(map));

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			tmp_map[r][M - c - 1] = map[r][c];
		}
	}

	memcpy(map, tmp_map, sizeof(tmp_map));
}

void Command_3()
{
	int tmp_map[100][100] = { 0, };

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			tmp_map[c][N - r - 1] = map[r][c];
		}
	}

	int n = N;
	N = M;
	M = n;
	memcpy(map, tmp_map, sizeof(tmp_map));
}

void Command_4()
{
	int tmp_map[100][100] = { 0, };

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			tmp_map[M - c - 1][r] = map[r][c];
		}
	}

	int n = N;
	N = M;
	M = n;
	memcpy(map, tmp_map, sizeof(tmp_map));
}

void Command_5()
{
	int tmp_map[100][100] = { 0, };
	memcpy(tmp_map, map, sizeof(map));

	int n = N / 2;
	int m = M / 2;

	int s1 = 0, c1 = 0;
	int s2 = 0, c2 = m;
	int s3 = n, c3 = 0;
	int s4 = n, c4 = m;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			tmp_map[s2 + r][c2 + c] = map[r][c];
		}
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = m; c < M; c++)
		{
			tmp_map[s4 + r][c4 + c - m] = map[r][c];
		}
	}

	for (int r = n; r < N; r++)
	{
		for (int c = m; c < M; c++)
		{
			tmp_map[s3 + r - n][c3 + c - m] = map[r][c];
		}
	}

	for (int r = n; r < N; r++)
	{
		for (int c = 0; c < m; c++)
		{
			tmp_map[s1 + r - n][c1 + c] = map[r][c];
		}
	}

	memcpy(map, tmp_map, sizeof(tmp_map));
}

void Command_6()
{
	int tmp_map[100][100] = { 0, };
	memcpy(tmp_map, map, sizeof(map));

	int n = N / 2;
	int m = M / 2;

	int s1 = 0, c1 = 0;
	int s2 = 0, c2 = m;
	int s3 = n, c3 = 0;
	int s4 = n, c4 = m;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			tmp_map[s3 + r][c3 + c] = map[r][c];
		}
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = m; c < M; c++)
		{
			tmp_map[s1 + r][c1 + c - m] = map[r][c];
		}
	}

	for (int r = n; r < N; r++)
	{
		for (int c = m; c < M; c++)
		{
			tmp_map[s2 + r - n][c2 + c - m] = map[r][c];
		}
	}

	for (int r = n; r < N; r++)
	{
		for (int c = 0; c < m; c++)
		{
			tmp_map[s4 + r - n][c4 + c] = map[r][c];
		}
	}

	memcpy(map, tmp_map, sizeof(tmp_map));
}

void debug()
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cout << map[r][c] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < M; c++)
		{
			cin >> map[r][c];
		}
	}

	for (int i = 0; i < R; i++)
	{
		int command;
		cin >> command;
		switch (command)
		{
			case 1: // 상하 반전
				Command_1();
				break;
			case 2: // 좌우 반전
				Command_2();
				break;
			case 3: // 시 90
				Command_3();
				break;
			case 4: // 반 90
				Command_4();
				break;
			case 5: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 2, 2 -> 3, 3 -> 4, 4 -> 1
				Command_5();
				break;
			case 6: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 4, 2 -> 1, 3 -> 2, 4 -> 3
				Command_6();
				break;
			default:
				break;
		}
	}
	debug();
}