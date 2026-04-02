#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // string 헤더 추가
#include <utility> // utility 헤더 추가

using namespace std;

vector<pair<int, string>> v;

bool cmp(const pair<int, string>& it1, const pair<int, string>& it2)
{
    return it1.first < it2.first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        v.push_back({age, name});
    }

    stable_sort(v.begin(), v.end(), cmp);

    for(auto& it : v)
    {
        cout << it.first << " " << it.second << "\n";
    }
}