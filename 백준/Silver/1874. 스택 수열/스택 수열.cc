#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<int> s;

    int n;
    cin >> n;

    int value = 1;
    vector<string> v;
    for(int i=0; i<n; i++)
    {
        int m;
        cin >> m;
        if(!s.empty() && s.top() == m)
        {
            while(!s.empty() && s.top() >= m)
            {
                s.pop();
                v.push_back("-");
            }
        }
        else if(value > m && s.top() < m)
        {
            v.clear();
            v.push_back("NO");
            break;
        }
        else
        {
            while(value <= m)
            {
                s.push(value);
                value++;
                v.push_back("+");
            }
            s.pop();
            v.push_back("-");
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << (i != v.size()-1 ? "\n" : "");
    }
}