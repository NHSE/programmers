#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[128][128];
int N, R, S;

// 부분배열을 찾고 연산 진행하는 방법은
// 좌표의 기준(최좌상단)을 기준으로 잡고 size 만큼 for문 돌리면 잡을 수 있음
// r += d로 부분배열의 최좌상단만 픽 가능

void flipDown(int sr, int sc, int size)
{
	int tmp_map[128][128];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			tmp_map[r][c] = map[sr + r][sc + c];
		}
	}

	for (int r = sr; r < sr + size; r++)
	{
		for (int c = sc; c < sc + size; c++)
		{
			int ox = r - sr, oy = c - sc;
			int nx = size - ox - 1, ny = oy;
			map[r][c] = tmp_map[nx][ny];
		}
	}
}

void Command_1(int level)
{
	int d = (1 << level);
	for (int r = 0; r < S; r += d)
	{
		for (int c = 0; c < S; c += d)
		{
			flipDown(r, c, d);
		}
	}
}

void flipLeft(int sr, int sc, int size)
{
	int tmp_map[128][128];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			tmp_map[r][c] = map[sr + r][sc + c];
		}
	}

	for (int r = sr; r < sr + size; r++)
	{
		for (int c = sc; c < sc + size; c++)
		{
			int ox = r - sr, oy = c - sc;
			int nx = ox, ny = size - oy - 1;
			map[r][c] = tmp_map[nx][ny];
		}
	}
}

void Command_2(int level)
{
	int d = (1 << level);
	for (int r = 0; r < S; r += d)
	{
		for (int c = 0; c < S; c += d)
		{
			flipLeft(r, c, d);
		}
	}
}

void fliprotate(int sr, int sc, int size)
{
	int tmp_map[128][128];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			tmp_map[r][c] = map[sr + r][sc + c];
		}
	}

	for (int r = sr; r < sr + size; r++)
	{
		for (int c = sc; c < sc + size; c++)
		{
			int ox = r - sr, oy = c - sc;
			int nx = oy, ny = size - ox - 1;
			map[r][c] = tmp_map[nx][ny];
		}
	}
}

void fliprotate_(int sr, int sc, int size)
{
	int tmp_map[128][128];
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			tmp_map[r][c] = map[sr + r][sc + c];
		}
	}

	for (int r = sr; r < sr + size; r++)
	{
		for (int c = sc; c < sc + size; c++)
		{
			int ox = r - sr, oy = c - sc;
			int nx = size - oy - 1, ny = ox;
			map[r][c] = tmp_map[nx][ny];
		}
	}
}

void Command_3(int level)
{
	int d = (1 << level); // 각 부분배열의 크기
	for (int r = 0; r < S; r += d)
	{
		for (int c = 0; c < S; c += d)
		{
			fliprotate_(r, c, d);
		}
	}
}

void Command_4(int level)
{
	int d = (1 << level); // 각 부분배열의 크기
	for (int r = 0; r < S; r += d)
	{
		for (int c = 0; c < S; c += d)
		{
			fliprotate(r, c, d);
		}
	}
}

void Command_5(int level)
{
	Command_1(N);
	Command_1(level);
}

void Command_6(int level)
{
	Command_2(N);
	Command_2(level);
}

void Command_7(int level)
{
	Command_3(N);
	Command_4(level);
}

void Command_8(int level)
{
	Command_4(N);
	Command_3(level);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> R;

	S = (1 << N);

	for (int r = 0; r < S; r++)
	{
		for (int c = 0; c < S; c++)
		{
			cin >> map[r][c];
		}
	}

	for (int i = 0; i < R; i++)
	{
		int command, level;
		cin >> command >> level;
		switch (command)
		{
		case 1: // 상하 반전
			Command_1(level);
			break;
		case 2: // 좌우 반전
			Command_2(level);
			break;
		case 3: // 시 90
			Command_3(level);
			break;
		case 4: // 반 90
			Command_4(level);
			break;
		case 5: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 2, 2 -> 3, 3 -> 4, 4 -> 1
			Command_5(level);
			break;
		case 6: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 4, 2 -> 1, 3 -> 2, 4 -> 3
			Command_6(level);
			break;
		case 7: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 4, 2 -> 1, 3 -> 2, 4 -> 3
			Command_7(level);
			break;
		case 8: //N/2 * M/2인 4개의 부분 배열 나눈 후 1 -> 4, 2 -> 1, 3 -> 2, 4 -> 3
			Command_8(level);
			break;
		default:
			break;
		}
	}

	for (int r = 0; r < S; r++)
	{
		for (int c = 0; c < S; c++)
		{
			cout << map[r][c] << " ";
		}
		cout << endl;
	}
}