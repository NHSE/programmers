#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long min, max;
    cin >> min >> max;

    vector<long long> v1(max - min + 1);
    for(long long i = min; i <= max; i++)
    {
        v1[i - min] = i;  // 인덱스 수정 (i - min)
    }

    int count = 0;
    long long i = 2;
    while(i * i <= max)  // i는 제곱근 이하의 수
    {
        long long j = i * i;  // i의 제곱수
        
        // min 이상에서 가장 작은 배수를 찾기
        long long start = min / j;
        if (min % j != 0) start++;  // 나누어 떨어지지 않으면 한 칸 증가
        start *= j;  // start를 제곱수의 배수로 맞춤

        for(long long z = start; z <= max; z += j)
        {
            if(v1[z - min] != 0)  // 올바른 인덱싱 (z - min)
            {
                v1[z - min] = 0;
                count++;
            }
        }
        i++;
    }

    cout << (max - min + 1) - count;
}
