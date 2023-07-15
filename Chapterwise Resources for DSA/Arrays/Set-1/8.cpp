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
int main()
{
    vector<int> v;
    v.push_back(-5);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(0);
    cout << firstMissingPositive(v);
}