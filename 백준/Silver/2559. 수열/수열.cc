#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    vector<int> sum;
    for(int i=0; i<n-k+1; i++)
    {
        int temp = 0;
        int index = i;
        int temp_sum = 0;

        while(temp < k)
        {
            temp_sum += v[index];
            temp++;
            index++;
        }
        sum.push_back(temp_sum);
    }
    int max = *max_element(sum.begin(), sum.end());

    cout << max;
}