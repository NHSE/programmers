#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> v;
    for(int i=0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(v[0].second);
    int cnt = 0;
    for(int i=1; i<N; i++)
    {
        if(q.top() <= v[i].first)
        {
            q.pop();
            q.push(v[i].second);
        }
        else
        {
            q.push(v[i].second);
        }
    }
    cout << q.size();
}