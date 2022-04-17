// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int fs, ref_str[100], n, faults = 0, hits = 0, frm_cntr = 0, far_index, res;
//     cout << "Frame size: \n";
//     vector<int> q;

//     cin >> fs;
//     cout << "Page Size: \n";
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> ref_str[i];
//     }

//     bool init_flag = true;

//     for (int i = 0; i < n; i++)
//     {

//         if (q.size() < fs)
//         {
//             faults++;
//             q.push_back(ref_str[i]);
//         }
//         else
//         {
//             if (find(q.begin(), q.end(), ref_str[i]) != q.end())
//             {
//                 hits++;
//             }
//             else
//             {

//                 far_index, res = -1;
//                 for (int m = 0; m < fs; m++)
//                 {
//                     for (int j = i; j < n; j++)
//                     {
//                         if (q[m] == ref_str[j])
//                         {
//                             if (far_index > j)
//                             {
//                                 far_index = j;
//                                 res = 1;
//                             }
//                         }
//                     }
//                 }
//                 if (!res)
//                 {
//                     q[far_index] = ref_str[i];
//                 }
//                 else
//                 {
//                     q[0] = ref_str[i];
//                 }

//                 frm_cntr++;
//                 frm_cntr = frm_cntr % fs;
//                 faults++;
//             }
//         }
//     }

//     cout << "Hits" << hits << endl;
//     cout << "Faults \n"
//          << faults;

//     return 0;
// }

// CPP program to demonstrate optimal page
// replacement algorithm.
#include <bits/stdc++.h>
using namespace std;

// Function to check whether a page exists
// in a frame or not
bool search(int key, vector<int> &fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}

// Function to find the frame that will not be used
// recently in future after given index in pg[0..pn-1]
int predict(int pg[], vector<int> &fr, int pn, int index)
{
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // If a page is never referenced in future,
        // return it.
        if (j == pn)
            return i;
    }

    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
    // Create an array for given number of
    // frames and initialize it as empty.
    vector<int> fr;

    // Traverse through page reference array
    // and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < pn; i++)
    {

        // Page found in a frame : HIT
        if (search(pg[i], fr))
        {
            hit++;
            continue;
        }

        // Page not found in a frame : MISS

        // If there is space available in frames.
        if (fr.size() < fn)
            fr.push_back(pg[i]);

        // Find the page to be replaced.
        else
        {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}

// Driver Function
int main()
{
    int pg[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;
    optimalPage(pg, pn, fn);
    return 0;
}
