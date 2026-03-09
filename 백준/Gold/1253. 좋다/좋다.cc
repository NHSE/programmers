#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());

    int count = 0;

    for(int k=0; k<n; k++)
    {
        int value = v[k];
        int i = 0, j = v.size()-1;
        while(i < j)
        {
            if(v[i] + v[j] > value)
            {
                j--;
            }
            else if(v[i] + v[j] < value)
            {
                i++;
            }
            else if(v[i] + v[j] == value)
            {
                if(i == k)
                {
                    i++;
                }
                else if(j == k)
                {
                    j--;
                }
                else if(i != k && j != k)
                {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
}