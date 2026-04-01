#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0; i<s.size(); i++)
    {
        char temp = s[i];
        if(temp == ' ')
        {
            answer += temp;
            continue;
        }
        for(int j=0; j<n; j++)
        {
            cout << temp << endl;
            temp += 1;
            if(temp > 'Z' && temp < 'a')
            {
                temp = 'A';
            }
            else if(temp > 'z')
            {
                temp = 'a';
            }
        }
        
        answer += temp;
    }
    return answer;
}