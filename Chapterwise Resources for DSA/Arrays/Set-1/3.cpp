#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int k = 0;
    for (auto i : nums)
        k ^= i;
    for (int i = 0; i <= nums.size(); i++)
    {
        k ^= i;
    }
    return k;
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout << missingNumber(v);
}