#include <bits/stdc++.h>
using namespace std;
bool findQueue(queue<int> q, int x)
{
    while (!q.empty())
    {
        if (x == q.front())
            return true;
        q.pop();
    }
    return false;
}
void LRU_Approximation(vector<int> t, int cpcty)
{
    int n = t.size();
    queue<int> q;
    int hits = 0, faults = 0;
    bool bitref[cpcty] = {false};
    int ptr = 0;
    int cnt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (!findQueue(q, t[i]))
        {
            if (cnt < cpcty)
            {
                q.push(t[i]);
                cnt++;
            }
            else
            {
                ptr = 0;
                while (!q.empty())
                {
                    if (bitref[ptr % cpcty])
                        bitref[ptr % cpcty] = !bitref[ptr % cpcty];
                    else
                        break;
                    ptr++;
                }
                if (q.empty())
                {
                    q.pop();
                    q.push(t[i]);
                }
                else
                {
                    int j = 0;
                    while (j < (ptr % cpcty))
                    {
                        int t1 = q.front();
                        q.pop();
                        q.push(t1);
                        bool temp = bitref[0];
                        for (int cntr = 0; cntr < cpcty - 1;
                             cntr++)
                            bitref[cntr] = bitref[cntr + 1];
                        bitref[cpcty - 1] = temp;
                        j++;
                    }
                    q.pop();
                    q.push(t[i]);
                }
            }
            faults++;
        }
        else
        {
            queue<int> temp = q;
            int cntr = 0;
            while (!q.empty())
            {
                if (q.front() == t[i])
                    bitref[cntr] = true;
                cntr++;
                q.pop();
            }
            q = temp;
            hits++;
        }
    }
    cout << "Hits: " << hits << "\nFaults: " << faults << '\n';
}
int main()
{
    vector<int> t = {2, 3, 2, 5, 3, 2, 5, 2};
    int cpcty = 4;
    LRU_Approximation(t, cpcty);
    return 0;
}