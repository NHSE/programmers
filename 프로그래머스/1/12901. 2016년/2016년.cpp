#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Data[13][31];

enum {SUN = 0, MON, TUE, WED, THU, FRI, SAT};

int Get_Number(int i)
{
    switch(i)
    {
        case 1:
            return 31;
        case 2:
            return 29;
        case 3:
            return 31;
        case 5:
            return 31;
        case 7:
            return 31;
        case 8:
            return 31;
        case 10:
            return 31;
        case 12:
            return 31;
        default:
            return 30;
    }
}

void Insert_Calendar()
{
    int day = FRI;
    for(int i=1; i<=12; i++)
    {
        int cnt = Get_Number(i);
        for(int j=1; j<=cnt; j++)
        {
            Data[i][j] = day;
            day = (day + 1) % 7;
        }
    }
}

string Get_Day(int a, int b)
{
    switch(Data[a][b])
    {
        case SUN:
            return "SUN";
        case MON:
            return "MON";
        case TUE:
            return "TUE";
        case WED:
            return "WED";
        case THU:
            return "THU";
        case FRI:
            return "FRI";
        case SAT:
            return "SAT";
    }
}

string solution(int a, int b) {
    Insert_Calendar();
    string answer = Get_Day(a, b);
    return answer;
}