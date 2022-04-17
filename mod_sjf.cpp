#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct process_struct
{

    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, start_time;

} ps[100];

int main()
{
    int n;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "AT" << i;
        cin >> ps[i].at;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "BT" << i;
        cin >> ps[i].bt;
    }

    int complete = 0;
    int curr_time = 0;

    while (complete != n)
    {
        int min_index = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].bt < minimum)
            {
                minimum = ps[i].bt;
                min_index = i;
            }
            if (ps[i].bt == minimum)
            {
                if (ps[i].at < ps[min_index].at)
                {
                    minimum = ps[i].bt;
                    min_index = i;
                }
            }
        }
        if (min_index != -1)
        {
            // computation
            ps[min_index].ct = ps[min_index].start_time + ps[min_index].bt;
            ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
            ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;

            ps[min_index].rt = ps[min_index].wt;

            sum_tat += ps[min_index].tat;
            sum_wt += ps[min_index].wt;
            sum_rt += ps[min_index].rt;
        }
        else
        {
            complete++;
        }
    }

    // Output
    cout << "\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << ps[i].at << "\t" << ps[i].bt << "\t\t" << ps[i].ct << "\t" << ps[i].tat << "\t" << ps[i].wt << "\t" << ps[i].rt << endl;
    cout << endl;
    return 0;
}