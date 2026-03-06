#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

bool Break_Point(int K)
{
    if(!q.empty())
    {
        int data = q.top();
        
        if(data < K)    return false;
        else            return true;
    }
    else return false;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i=0; i<scoville.size(); i++)
    {
        q.push(scoville[i]);
    }
    
    while(1)
    {
        if(Break_Point(K))   break;
        if(q.size() == 1)
        {
            answer = -1;
            break;
        }
        
        //스코빌 합치기
        if(q.size() >= 2)
        {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();

            int next = first + (second * 2);
            q.push(next);
        }
        
        answer++;
    }
    return answer;
}