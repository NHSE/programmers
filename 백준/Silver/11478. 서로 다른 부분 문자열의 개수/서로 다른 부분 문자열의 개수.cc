#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    unordered_set<string> set;

    int i = 1;
    int standard = s.size()-1;
    int index = standard;
    while(i <= s.size())
    {
        if(index < 0)
        {
            i++;
            index = standard;
        }
        else
        {
            string temp = s.substr(standard - index, i);
            set.insert(temp);
            index--;
        }
    }
    cout << set.size() << "\n";
}