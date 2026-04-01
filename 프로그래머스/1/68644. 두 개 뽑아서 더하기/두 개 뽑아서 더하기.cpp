#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

bool visited[MAX] = {false, };

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++)
    {
        int a = numbers[i];
        for(int j=i+1; j<numbers.size(); j++)
        {
            int b = numbers[j];
            
            int sum = a + b;
            if(!visited[sum])
            {
                visited[sum] = true;
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}