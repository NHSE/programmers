#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long A,B;
    cin >> A >> B;

    vector<long long> v(sqrt(B)+1);

    for(int i=2; i<=sqrt(B); i++)
    {
        v[i] = i;
    }

    for(int i=2; i<=sqrt(B); i++)
    {
        if(v[i] == 0)
            continue;
        for(int j=i+i; j<=sqrt(B); j=j+i)
        {
            v[j] = 0;
        }
    }

    int answer = 0;
    for(int i=2; i<=sqrt(B); i++)
    {
        if(v[i] == 0)
            continue;
        long long  temp = v[i] * v[i];
        while (temp <= B)
        {
            if(temp >= A)
            {
                answer++;
            }
            if(temp > B / v[i])  // 오버플로우 방지
                break;
            temp = temp * v[i];
        }
    }
    cout << answer;
}