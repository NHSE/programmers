#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    //최대 공약수
    int min_value = min(n, m);
    int min_number = 0;
    for(int i=1; i<=min_value; i++)
    {
        if(n % i == 0 && m % i == 0)
        {
            min_number = max(i, min_number);
        }
    }
    //최소 공배수
    int max_value = max(n, m);
    int max_number = 0;
    for(int i=2; i<=max_value; i++)
    {
        int value = min_value * i;
        if(value < max_value)   continue;
        cout << value << endl;
        
        if(value % min_value == 0 && (max_value % value == 0 || value % max_value == 0))
        {
            max_number = value;
            break;
        }
    }
    
    answer.push_back(min_number);
    answer.push_back(max_number);
    return answer;
}