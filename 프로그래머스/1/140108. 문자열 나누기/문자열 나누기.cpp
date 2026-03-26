#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int correct = 1, not_correct = 0;
    char prev, curr;
    bool flag = false;
    for(int i=0; i<s.size(); i++)
    {
        if(!flag)
        {
            prev = s[i];
            flag = true;
            cout << prev;
            continue;
        }
        else
        {
            curr = s[i];
        }
        
        cout << curr;
        
        if(curr == prev)
        {
            correct++;
        }
        else
        {
            not_correct++;
        }
        
        if(correct == not_correct)
        {
            correct = 1, not_correct = 0;
            answer++;
            flag = false;
            cout << " ";
        }
    }
    
    if(flag)    answer++;
    
    return answer;
}