#include <bits/stdc++.h>
using namespace std;

static bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
vector<int> frequencySort(vector<int> &nums)
{
    vector<pair<int, int>> vp;
    unordered_map<int, int> m;
    for (auto i : nums)
        m[i]++;

    for (auto i : m)
        vp.push_back(make_pair(i.second, i.first));

    sort(vp.begin(), vp.end(), comp);
    vector<int> ans;
    for (auto i : vp)
    {
        int n = i.first;
        while (n--)
            ans.push_back(i.second);
    }
    return ans;
}