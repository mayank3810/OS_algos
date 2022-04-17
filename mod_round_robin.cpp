#include <iostream>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <climits>

using namespace std;

struct process_struct
{

    int pid;
    int at;
    int bt;
    int bt_r;
    int ct, wt, tat, rt, start_time;

} ps[100];
// compare

bool comparatorAT(struct process_struct a, struct process_struct b)
{

    return a.at < b.at;
}

int main()
{

    int n;
    bool visited[100] = {false};
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    cout << "no of process";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "AT" << i;
        cin >> ps[i].at;
        ps[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "BT" << i;
        cin >> ps[i].bt;
        ps[i].bt_r = ps[i].bt;
    }

    int tq;
    cout << "Enter time qunatum";
    cin >> tq;

    sort(ps, ps + n, comparatorAT);

    int completed = 0;
    int curr_time = 0;
    queue<int> q;

    q.push(0);
    visited[0] = true;

    int index;
    int start_time;

    while (completed != n)
    {
        index = q.front();
        q.pop();

        // if(ps[index].bt_r == ps[index].bt) {

        //     start_time = max(ps[index].at, curr_time);

        // }

        if (ps[index].bt_r == ps[index].bt)
        {
            ps[index].start_time = max(curr_time, ps[index].at);
            curr_time = ps[index].start_time;
        }

        if (ps[index].bt_r - tq > 0)
        {
            ps[index].bt_r -= tq;
            curr_time += tq;
        }
        else
        {
            curr_time += ps[index].bt_r;
            ps[index].bt_r = 0;
            completed++;

            ps[index].ct = curr_time;
            ps[index].tat = ps[index].ct - ps[index].at;
            ps[index].wt = ps[index].tat - ps[index].bt;
            ps[index].rt = ps[index].start_time - ps[index].at;

            sum_tat += ps[index].tat;
            sum_wt += ps[index].wt;
            sum_rt += ps[index].rt;
        }

        for (int i = 0; i < n; i++)
        {
            if (ps[i].bt_r > 0 && visited[i] == false && ps[i].at <= curr_time)
            {
                q.push(ps[i].pid);
                visited[i] = true;
            }
            if (ps[index].bt_r > 0)
            {
                q.push(index);
            }

            if (q.empty())
            {
                for (int i = 0; i < n; i++)
                {
                    if (ps[i].bt_r > 0)
                    {
                        q.push(i);
                        visited[i] = true;
                        break;
                    }
                }
            }
        }
    }

    cout << "\nProcess No.\tAT\tCPU Burst Time\tStart Time\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << ps[i].at << "\t" << ps[i].bt << "\t\t" << ps[i].start_time << "\t\t" << ps[i].ct << "\t" << ps[i].tat << "\t" << ps[i].wt << "\t" << ps[i].rt << endl;
    cout << endl;

    return 0;
}
