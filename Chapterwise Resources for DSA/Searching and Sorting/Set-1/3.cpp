#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;
    vector<int> ans;
    while (r > l)
    {
        int m = numbers[l] + numbers[r];
        if (m == target)
        {
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            return ans;
        }
        else if (m > target)
        {
            r--;
        }
        else
        {
            l++;
        }
    }
    return ans;
}