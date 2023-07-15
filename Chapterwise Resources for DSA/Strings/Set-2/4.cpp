#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int idx_1 = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            idx_1 = i;
            break;
        }
    }
    if (idx_1 == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int idx_2, mini = INT_MAX;
    for (int i = idx_1 + 1; i < n; i++)
    {
        if (mini > nums[i] and nums[i] > nums[idx_1])
        {
            idx_2 = i;
            mini = nums[i];
        }
    }
    //cout<<idx_1<<" "<<idx_2;
    swap(nums[idx_1], nums[idx_2]);
    sort(nums.begin() + idx_1 + 1, nums.end());
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    nextPermutation(v);
    for (auto i : v)
    {
        cout << i << " ";
    }
}