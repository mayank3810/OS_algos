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

bool comparatorAT(struct process_struct a, struct process_struct b)
{

    return a.at < b.at;
}

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
        cin >> ps[i].at;
    }

    sort(ps, ps + n, comparatorAT);

    for (int i = 0; i < n; i++)
    {
        ps[i].start_time = (i == 0) ? ps[i].at : max(ps[i].at, ps[i - 1].ct);

        ps[i].ct = ps[i].start_time + ps[i].bt;
        ps[i].tat = ps[i].ct - ps[i].at;
        ps[i].wt = ps[i].tat - ps[i].bt;

        ps[i].rt = ps[i].wt;

        sum_tat += ps[i].tat;
        sum_wt += ps[i].wt;
        sum_rt += ps[i].rt;
    }
    cout << "Process No. \tArrival Time \tBurst Time \tCT \tTAT \tWT \tRT\n";

    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << ps[i].at << "\t" << ps[i].bt << "\t\t" << ps[i].ct << "\t" << ps[i].tat << "\t" << ps[i].wt << "\t" << ps[i].rt << endl;
        cout << endl;
    }

    return 0;
}