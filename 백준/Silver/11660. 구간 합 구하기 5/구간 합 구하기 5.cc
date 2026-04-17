#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> org(n+1, vector<int>(n+1, 0));
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++) // 원본 배열 저장
    {
        for(int j=1; j<=n; j++)
        {
            cin >> org[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] 
            - sum[i-1][j-1] + org[i][j];
        }
    }

    int result = 0;
    for(int i=0; i<m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        result = sum[x2][y2] - sum[x1-1][y2]
                - sum[x2][y1-1] + sum[x1-1][y1-1];
        cout << result << "\n";
    }
}
