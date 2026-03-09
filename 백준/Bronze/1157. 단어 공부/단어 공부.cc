#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin() ,::toupper);
    
    map<char, int> m;
    
    char output;
    bool check = false;
    int max_ = 0, max_temp = 0;
    for(auto& it : s)
    {
        m[it]++;
    }

    for(auto& it : m)
    {
        max_temp = it.second;
        if(max_temp > max_)
        {
            max_ = max_temp;
            output = it.first;
            check = false;
        }
        else if(max_temp == max_)
        {
            check = true;
        }
    }
    if(check)
        cout << "?" << endl;
    else
        cout << output << endl;
    
    return 0;
}