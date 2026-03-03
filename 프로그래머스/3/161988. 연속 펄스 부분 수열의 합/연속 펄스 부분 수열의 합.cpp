#include <string>
#include <vector>
#include <iostream>

#define MAX 500001

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    bool flag = false;
    long long prefix[MAX] = {0, };

    prefix[1] = sequence[0];
    
    for(int i=1; i<sequence.size(); i++)
    {
        if(flag)
        {
            prefix[i+1] = sequence[i] + prefix[i];
        }
        else
        {
            prefix[i+1] = -sequence[i] + prefix[i];
        }
        
        flag = !flag;
    }
    
    long long max_value = -1e18, min_value = 1e18;
    
    for(int i=0; i<=sequence.size(); i++)
    {
        max_value = max(prefix[i], max_value);
        min_value = min(prefix[i], min_value);
        //cout << max_value << " " << prefix[i] << endl;
    }
    
    answer = max_value - min_value;
    return answer;
}