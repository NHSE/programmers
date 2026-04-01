#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    int f_point = 0, e_point = people.size() - 1;
    while(1)
    {
        if(f_point > e_point)  break;
        
        if(f_point == e_point)
        {
            answer++;
            break;
        }
        
        int f_weight = people[f_point];
        int e_weight = people[e_point];
        
        int sum = f_weight + e_weight;
        if(limit >= sum)
        {
            answer++;
            f_point++, e_point--;
        }
        else if(limit < sum)
        {
            answer++;
            e_point--;
        }
    }
    
    return answer;
}