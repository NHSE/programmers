#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> v = {{'a', 'y', 'a'}, {'y', 'e'}, {'w', 'o', 'o'}, {'m', 'a'}};

pair<int, int> Checking(char A)
{
    pair<int, int> ret;
    switch(A)
    {
        case 'a' :
            ret.first = 0, ret.second = 1;
            break;
        case 'y' :
            ret.first = 1, ret.second = 1;
            break;
        case 'w' :
            ret.first = 2, ret.second = 1;
            break;
        case 'm' :
            ret.first = 3, ret.second = 1;
            break;
        default :
            ret.first = -1, ret.second = -1;
            break;
    }
    
    return ret;
}

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i=0; i<babbling.size(); i++)
    {
        int first = -1, second = 0;
        int prev_first = -1;
        
        bool flag = false;
        
        for(int j=0; j<babbling[i].size(); j++)
        {
            if(first != -1)
            {
                if(v[first][second] == babbling[i][j])
                {
                    second++;
                }
                else
                {
                    flag = false;
                    break;
                }
                
                //완료 시 초기화 및 증가
                if(v[first].size() <= second)
                {                  
                    flag = true;
                    prev_first = first;
                    first = -1, second = -1;
                }
            }
            else
            {
                pair<int, int> ret = Checking(babbling[i][j]);
                if(ret.first == prev_first || ret.first == -1) 
                {
                    flag = false;
                    break;
                }
                first = ret.first, second = ret.second;
            }
        }
        
        if(flag)    
        {
            cout << i << endl;
            answer++;
        }
    }
    return answer;
}