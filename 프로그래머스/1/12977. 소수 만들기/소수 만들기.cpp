#include <vector>
#include <iostream>

using namespace std;

vector<int> number;
int answer = 0;

bool Check_Number(int sum)
{
    for(int i=2; i<sum; i++)
    {
        if(sum % i == 0)    return false;
    }
    
    return true;
}

void DFS(int num, int sum, int depth)
{
    if(depth == 3)
    {
        if(Check_Number(sum))
        {
            cout << sum << endl;
            answer++;
        }
        
        return;
    }
    
    for(int i=num; i<number.size(); i++)
    {
        sum += number[i];
        DFS(i+1, sum, depth + 1);
        sum -= number[i];
    }
}

int solution(vector<int> nums) {

    number = nums;
    
    DFS(0, 0, 0);

    return answer;
}