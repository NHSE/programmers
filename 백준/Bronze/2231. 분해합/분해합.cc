#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int min_ = 1e9;

    for(int i=n; i>=0; i--)
    {
        string s = to_string(i);
        int a = 0;
        for(int j=0; j<s.size(); j++)
        {
            a += s[j] - '0';
        }
        if(min_ > i && n == i + a)
        {
            min_ = i;
        }

    }

    if(min_ != 1e9)
        cout << min_ << "\n";
    else
        cout << "0" << "\n";
}