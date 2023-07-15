#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> solution;
    int i = 0, j = 0;
    // int m = nums1.size(), n = nums2.size();

    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            solution.push_back(nums1[i]);
            i += 1;
        }
        else
        {
            solution.push_back(nums2[j]);
            j += 1;
        }
    }
    while (i < m)
    {
        solution.push_back(nums1[i]);
        i += 1;
    }
    while (j < n)
    {
        solution.push_back(nums2[j]);
        j += 1;
    }
    nums1 = solution;
}

int main()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(10);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(7);
    v2.push_back(13);
    merge(v1, 5, v2, 5);
    for (auto i : v1)
    {
        cout << i << " ";
    }
}