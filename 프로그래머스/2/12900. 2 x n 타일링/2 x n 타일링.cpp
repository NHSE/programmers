#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if(n == 1)  return 1;
    else if(n == 2) return 2;
    else
    {
        int prev = 2, pprev = 1;
        for(int i=3; i<=n; i++)
        {
            answer = (prev + pprev) % 1000000007;
            pprev = prev, prev = answer;
        }
    }
    return answer;
}