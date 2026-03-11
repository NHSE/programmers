#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> stk;

void command_run(int command, int x)
{
    switch(command)
    {
        case 1 :
        {
            stk.push(x);
        }
        break;
        case 2 :
        {
            if(stk.empty())
                cout << "-1" << "\n";
            else
            {
                cout << stk.top() << "\n";
                stk.pop();
            }
        }
        break;
        case 3 :
        {
            cout << stk.size() << "\n";
        }
        break;
        case 4 :
        {
            if(stk.empty())
                cout << "1" << "\n";
            else
                cout << "0" << "\n";
        }
        break;
        case 5 :
        {
            if(stk.empty())
                cout << "-1" << "\n";
            else
                cout << stk.top() << "\n";
        }
        break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, command, x;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> command;
        if(command == 1)
        {
            cin >> x;
            command_run(command, x);
        }
        else
        {
            command_run(command, 0);
        }
    }
}