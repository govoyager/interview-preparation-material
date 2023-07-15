#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int mini = INT_MAX;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        mini = min(mini, arr[i + 1] - arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (mini == arr[i + 1] - arr[i])
        {
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[i + 1]);
            ans.push_back(temp);
        }
    }
    return ans;
}
