#include <bits/stdc++.h>
using namespace std;

int getMinDistance(vector<int> &nums, int target, int start)
{
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            ans = min(ans, abs(i - start));
        }
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << getMinDistance(v, 5, 3);
}