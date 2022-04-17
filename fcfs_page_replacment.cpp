#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int fs, ref_str[100], n, faults = 0, hits = 0, frm_cntr = 0;
    cout << "Frame size: \n";
    vector<int> q;

    cin >> fs;
    cout << "Page Size: \n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ref_str[i];
    }

    bool init_flag = true;

    for (int i = 0; i < n; i++)
    {

        if (q.size() < fs)
        {
            faults++;
            q.push_back(ref_str[i]);
        }
        else
        {
            if (find(q.begin(), q.end(), ref_str[i]) != q.end())
            {
                hits++;
            }
            else
            {

                q[frm_cntr] = ref_str[i];
                frm_cntr++;
                frm_cntr = frm_cntr % fs;
                faults++;
            };
        }
    }

    cout << "Hits" << hits << endl;
    cout << "Faults \n"
         << faults;

    return 0;
}