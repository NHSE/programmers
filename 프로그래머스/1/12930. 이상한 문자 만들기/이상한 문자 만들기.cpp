#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt = 2;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
        {
            answer += s[i];
            cnt = 0;
            continue;
        }

        if((cnt % 2) == 0)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                answer += s[i];
            else
                answer += s[i] - 32;
        }
        else
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                answer += s[i];
            else
                answer += s[i] + 32;
        }
        
        cnt++;
    }
    return answer;
}