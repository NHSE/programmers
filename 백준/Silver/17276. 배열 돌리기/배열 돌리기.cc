#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int map[500][500];
int t, n, d;

void rotate()
{
	int tmp_map[500][500] = { 0, };

	memcpy(tmp_map, map, sizeof(map));

	int a = n / 2;

	for (int r = 0; r < n; r++) tmp_map[r][a] = map[r][r];

	for (int r = 0; r < n; r++) tmp_map[r][r] = map[a][r];

	for (int r = 0; r < n; r++) tmp_map[a][r] = map[n - r - 1][r];

	for (int r = 0; r < n; r++) tmp_map[n - r - 1][r] = map[n - r - 1][a];

	memcpy(map, tmp_map, sizeof(tmp_map));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cin >> map[r][c];
		}
	}

	while (t--)
	{
		cin >> n >> d;
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cin >> map[r][c];
			}
		}

		d = (d + 360) % 360;
		int cnt = d / 45;

		for (int i = 0; i < cnt; i++)
			rotate();

		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < n; c++)
			{
				cout << map[r][c] << " ";
			}
			cout << "\n";
		}
	}
}