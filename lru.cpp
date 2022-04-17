#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int fs, ref_str[100], n, faults = 0, hits = 0, frm_cntr = 0, far_index, res;
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

                far_index, res = -1;
                for (int m = 0; m < fs; m++)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (q[j] == ref_str[j])
                        {
                            if (far_index > j)
                            {
                                far_index = j;
                                res = 1;
                            }
                        }
                    }
                }
                if (!res)
                {
                    q[far_index] = ref_str[i];
                }
                else
                {
                    q[0] = ref_str[i];
                }

                frm_cntr++;
                frm_cntr = frm_cntr % fs;
                faults++;
            };
        }
    }

    cout << "Hits: " << hits << endl;
    cout << "Faults: "
         << faults;

    return 0;
}
