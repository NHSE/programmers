#include <string>
#include <vector>
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int temp;
    while(b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

int lcm(int a,int b)
{
    int c = (a * b) / gcd(a,b);
    return c;
}

int solution(vector<int> arr) {
    int prev = -1;
    for(int i=0; i<arr.size(); i++)
    {
        if(prev == -1)
            prev = arr[i];
        else
        {
            prev = lcm(prev, arr[i]);
        }
    }

    return prev;
}