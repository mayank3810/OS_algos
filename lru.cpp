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
//                     for (int j = 0; j < i; j++)
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
//             };
//         }
//     }

//     cout << "Hits: " << hits << endl;
//     cout << "Faults: "
//          << faults;

//     return 0;
// }

// C++ implementation of above algorithm
#include <bits/stdc++.h>
using namespace std;

// Function to find page faults using indexes
int pageFaults(int pages[], int n, int capacity)
{
    // To represent set of current pages. We use
    // an unordered_set so that we quickly check
    // if a page is present in set or not
    unordered_set<int> s;

    // To store least recently used indexes
    // of pages.
    unordered_map<int, int> indexes;

    // Start from initial page
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);

                // increment page fault
                page_faults++;
            }

            // Store the recently used index of
            // each page
            indexes[pages[i]] = i;
        }

        // If the set is full then need to perform lru
        // i.e. remove the least recently used page
        // and insert the current page
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Find the least recently used pages
                // that is present in the set
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }

                // Remove the indexes page
                s.erase(val);

                // insert the current page
                s.insert(pages[i]);

                // Increment page faults
                page_faults++;
            }

            // Update the current page index
            indexes[pages[i]] = i;
        }
    }

    return page_faults;
}

// Driver code
int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 4;
    cout << pageFaults(pages, n, capacity);
    return 0;
}
