#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int local_max = nums[0];
    int global_max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        local_max = max(nums[i], local_max + nums[i]);
        global_max = max(global_max, local_max);
    }
    return global_max;
}

int main()
{
    vector<int> v;
    v.push_back(-1);
    v.push_back(-5);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(-2);

    cout << maxSubArray(v);
}