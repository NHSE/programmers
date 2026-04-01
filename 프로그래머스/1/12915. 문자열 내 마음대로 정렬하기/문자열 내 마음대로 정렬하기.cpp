#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool cmp(string A, string B)
{
    char a = A[N], b = B[N];
    
    if(a != b)
        return a < b;
    else
        return A < B;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(), strings.end(), cmp);
    answer = strings;
    return answer;
}