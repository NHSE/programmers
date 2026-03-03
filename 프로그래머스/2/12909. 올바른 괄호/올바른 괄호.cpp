#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> a;

    for(auto& it : s)
    {
        if(it == ')')
        {
            if(a.empty())
            {
                return false;
            }
            else
            {
                if(a.top() == '(')
                {
                    a.pop();
                }
            }
        }
        else
        {
            a.push(it);
        }
    }
    if(!a.empty())
        return false;

    return answer;
}