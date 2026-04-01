#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string Change_Length(int length)
{
    string ret = "";
    
    while(1)
    {
        if(length < 2)
        {
            ret += to_string(length);
            break;
        }
        ret += to_string(length % 2);
        length = length / 2;
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<int> solution(string s) {
    vector<int> answer;
    int change_cnt = 0, zero_cnt = 0;
    while(1)
    {
        change_cnt++;
        
        string tmp;
        //0 제거
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '1') tmp += '1';
            else
            {
                zero_cnt++;
            }
        }
        
        s = tmp;
        if(s == "1") break;
        
        // 길이 -> 2진법
        int string_length = s.length();
        s = Change_Length(string_length);
        
        cout << s << endl;
        if(s == "1") break;
    }
    
    answer.push_back(change_cnt);
    answer.push_back(zero_cnt);
    return answer;
}