#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, int> m;

    int count = 0;

    int n_, m_;
    cin >> n_;
    cin >> m_;

    for(int i=0; i<n_; i++)
    {
        string s;
        cin >> s;
        m[s] = 1;
    }

    for(int i=0; i<m_; i++)
    {
        string s;
        cin >> s;
        auto it = m.find(s);
        if(it != m.end())
        {
            count++;
        }
    }
    cout << count << "\n";
}