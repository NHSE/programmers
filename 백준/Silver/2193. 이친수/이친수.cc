#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

long D[91][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	D[1][1] = 1, D[1][0] = 0;

	for (int i = 2; i <= N; i++)
	{
		D[i][0] = D[i - 1][1] + D[i - 1][0]; // 앞선 데이터에서 0으로 끝나는 부분, 1로 끝나는 부분에는 모두 끝에 0을 붙일 수 있기에 이전 데이터를 더함
		D[i][1] = D[i - 1][0];				 // 앞선 데이터에서 0으로 끝나는 부분만 1을 추가할 수 있기에 이전 데이터의 0으로 끝나는 부분만 더함
	}

	cout << D[N][0] + D[N][1];
}