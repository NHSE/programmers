#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<pair<int, int>> dq;

    int n, l;
    cin >> n >> l;

    int num = 0;
    for(int i=0; i<n; i++)
    {
        cin >> num;

        while(dq.size() && dq.back().second > num)
        {
            dq.pop_back();
        }

        dq.push_back(make_pair(i, num));
        if(dq.front().first <= i - l)
        {
            dq.pop_front();
        }
        cout << dq.front().second << " ";
    }
}