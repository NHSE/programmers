#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    char a[50][50]; // 체스판 저장
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }

    int min_changes = 1e9; // 최소 변경 횟수 저장

    // 8x8 체스판을 검사
    for(int i=0; i<=n-8; i++) {
        for(int j=0; j<=m-8; j++) {
            int change_B = 0, change_W = 0; // B로 시작, W로 시작 경우의 변경 횟수

            for(int k=0; k<8; k++) {
                for(int g=0; g<8; g++) {
                    char expected_B = ((k + g) % 2 == 0) ? 'B' : 'W';
                    char expected_W = ((k + g) % 2 == 0) ? 'W' : 'B';

                    if(a[i+k][j+g] != expected_B) change_B++;
                    if(a[i+k][j+g] != expected_W) change_W++;
                }
            }

            min_changes = min(min_changes, min(change_B, change_W));
        }
    }

    cout << min_changes << "\n";
}
