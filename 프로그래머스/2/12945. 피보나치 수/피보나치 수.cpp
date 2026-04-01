#include <string>
#include <vector>

using namespace std;

long F[100001];
int mod = 1234567;

int solution(int n) {
    int answer = 0;
    F[0] = 0, F[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        F[i] = (F[i - 1] + F[i - 2])  % mod;
    }
    
    answer = F[n];
    return answer;
}