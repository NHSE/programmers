#include <iostream>

using namespace std;

long long gcd(long long a, long long b);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long A, B;
    cin >> A >> B;

    int result = gcd(A, B);
    for(int i=0; i<result; i++)
    {
        cout << "1";
    }
}

long long gcd(long long a, long long b)
{
    if(a%b == 0)
        return b;
    else
        return gcd(b, a%b);
}