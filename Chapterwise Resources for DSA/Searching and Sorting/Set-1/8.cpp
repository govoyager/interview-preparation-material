#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0 && nums[i] <= n)
        {
            if (nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
                i -= 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
            return i + 1;
    }
    return n + 1;
}