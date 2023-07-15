#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            v.push_back(abs(nums[i]));
        }
        nums[abs(nums[i]) - 1] *= -1;
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v, s;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        v.push_back(tem);
    }
    s = findDuplicates(v);
    for (auto i : s)
    {
        cout << i << " ";
    }
}