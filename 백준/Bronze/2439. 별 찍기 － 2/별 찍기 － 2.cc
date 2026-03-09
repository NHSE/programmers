#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;

    int star = 1;
    int space = a - star;

    for(int i=0; i<a; i++)
    {
        for(int z=0; z < space; z++)
        {
            cout << " ";
        }

        for(int j=0; j < star; j++)
        {
            cout << "*";
        }
        cout << "\n";
        star++;
        space = a - star;
    }
}