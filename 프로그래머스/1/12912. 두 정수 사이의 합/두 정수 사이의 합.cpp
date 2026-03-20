#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int min_value = min(a, b);
    int max_value = max(a, b);
    
    for(int i=min_value; i<=max_value; i++)
        answer += i;
    return answer;
}