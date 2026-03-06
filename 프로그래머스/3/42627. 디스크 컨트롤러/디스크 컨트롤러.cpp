#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Data
{
    int start_time, dis_time;
};

struct HardDisk
{
    int time, res_time;
};

struct cmp
{
    bool operator()(const Data &a, const Data &b)
    {
        return a.dis_time > b.dis_time;
    }
};

struct cmp_1
{
    bool operator()(const Data &a, const Data &b)
    {
        return a.start_time > b.start_time;
    }
};

priority_queue<Data, vector<Data>, cmp> wq;
priority_queue<Data, vector<Data>, cmp_1> q;
queue<HardDisk> harddisk;

bool Break_Point()
{
    return wq.empty() && q.empty() && harddisk.empty();
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    for(int i=0; i<jobs.size(); i++)
    {
        q.push({jobs[i][0], jobs[i][1]});
    }

    int curr_time = 0;
    int start_time = 0;
    bool flag = false;

    while(1)
    {
        if(Break_Point()) break;

        // 도착한 작업 전부 wq 이동
        while(!q.empty() && q.top().start_time <= curr_time)
        {
            wq.push(q.top());
            q.pop();
        }

        // 작업 수행중
        if(flag)
        {
            HardDisk data = harddisk.front();

            if(start_time + data.time <= curr_time)
            {
                harddisk.pop();

                answer += curr_time - data.res_time;

                if(!harddisk.empty())
                {
                    start_time = curr_time;
                }
                else
                {
                    flag = false;
                }
            }
        }

        // 새로운 작업 시작
        if(!flag)
        {
            if(!wq.empty())
            {
                Data run = wq.top();
                wq.pop();

                harddisk.push({run.dis_time, run.start_time});

                start_time = curr_time;
                flag = true;
            }
        }

        curr_time++;
    }

    answer = answer / jobs.size();
    return answer;
}