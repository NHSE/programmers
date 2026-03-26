#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 1000001

bool value[MAX] = {false, };

int solution(int n) {
    int answer = 0;

    for(int i=2; i<=n; i++)
    {
        if(value[i])    continue;
        
        int v = i;
        int x = 2;
        while(1)
        {
            v = i * x;
            
            if(v > n)   break;
            
            value[v] = true;
            x++;
        }
    }
    
    for(int i=2; i<=n; i++)
    {
        if(!value[i])   
        {
            answer++;
        }
    }
    return answer;
}