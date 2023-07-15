#include <bits/stdc++.h>
using namespace std;

int dominantIndex(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return 0;
    }
    int first = INT_MIN;
    int second = INT_MIN;
    int index;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > first)
        {
            second = first;
            first = nums[i];
            index = i;
        }
        else if (nums[i] > second)
            second = nums[i];
    }
    if (2 * second <= first)
    {
        return index;
    }
    else
        return -1;
}

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(0);
    v.push_back(1);
    v.push_back(15);
    v.push_back(3);
    v.push_back(2);
    cout << dominantIndex(v);
}