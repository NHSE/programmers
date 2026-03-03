#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string Change_Number(int n)
{
    string ret = "";
    int tmp_n = n;
    
    while(1)
    {
        int next = tmp_n/2;
        ret += to_string(tmp_n%2);
        tmp_n = next;
        
        if(tmp_n <= 1)
        {
            ret += to_string(tmp_n);
            break;
        }
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

int Checking_One(string num)
{
    int ret = 0;
    for(int i=0; i<num.size(); i++)
    {
        if(num[i] == '1')   ret++;
    }
    
    return ret;
}

int Check_Number(int n)
{
    //2진수로 변환
    string num = Change_Number(n);
    
    //1의 갯수 리턴
    int ret = Checking_One(num);
    
    return ret;
}

int solution(int n) {
    int answer = 0;
    
    //2진수로 변환 -> 1의 갯수
    int cnt = Check_Number(n);
    
    //1의 갯수에 맞게 경우의 수 진행 -> n보다 크고 가장 작은 숫자
    int tmp_n = n + 1;
    while(1)
    {
        int tmp_cnt = Check_Number(tmp_n);
        if(tmp_cnt == cnt)
        {
            answer = tmp_n;
            break;
        }
        
        tmp_n++;
    }
    return answer;
}