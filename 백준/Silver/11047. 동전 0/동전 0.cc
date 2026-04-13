#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> v(N, 0);
    for(int i=N-1; i>=0; i--)
    {
        cin >> v[i];
    }

    int cnt = 0;

    while(K != 0)
    {
        for(int i=0; i<N; i++)
        {
            if(v[i] <= K)
            {
                cnt += K/v[i];
                K = K%v[i];
            }
        }
    }

    cout << cnt;
}