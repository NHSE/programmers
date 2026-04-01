#include <iostream>
#include <string>
#include <deque>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    deque<char> st;

    for(int i=0; i<s.size(); i++)
    {
        if(!st.empty() && st.back() == s[i])
        {
            st.pop_back();
        }
        else if(!st.empty() && st.back() != s[i])
        {
            st.push_back(s[i]);
        }
        else if(st.empty())
        {
            st.push_back(s[i]);
        }
    }
    
    if(st.size() == 0)  answer = 1;

    return answer;
}