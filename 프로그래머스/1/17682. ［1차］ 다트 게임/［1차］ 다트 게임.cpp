#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> result(3, 0);
    int index = -1;
    bool flag = false;
    string number = "";
    for(int i=0; i<dartResult.size(); i++)
    {
        if(dartResult[i] == '*')
        {
            if(index > 0) // 두번째 이상에서 스타상
            {
                result[index] = result[index] * 2;
                result[index-1] = result[index-1] * 2;
            }
            else // 첫번째만 점수 획득
            {
                result[index] = result[index] * 2;
            }
        }
        else if(dartResult[i] == '#')
        {
            result[index] = result[index] * (-1);
        }
        else if(dartResult[i] >= '0' && dartResult[i] <= '9')
        {
            if(number.empty())  index++;
            
            number += dartResult[i];
        }
        else if(dartResult[i] == 'S')
        {
            result[index] = stoi(number);
            number = "";
        }
        else if(dartResult[i] == 'D')
        {
            int num = stoi(number);
            result[index] = pow(num, 2);
            number = "";
        }
        else if(dartResult[i] == 'T')
        {
            int num = stoi(number);
            result[index] = pow(num, 3);
            number = "";
        }
    }
    
    for(int i=0; i<3; i++)
    {
        answer += result[i];
    }
    return answer;
}