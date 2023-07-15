#include <bits/stdc++.h>
using namespace std;

void rotateFunc(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= nums.size();
    reverse(nums.begin(), nums.begin() + (n - k));
    reverse(nums.begin() + (n - k), nums.end());
    reverse(nums.begin(), nums.end());
}

int main()
{
    int n, temp, k;
    vector<int> v;
    cin >> n >> k;
    int m = n;
    while (n--)
        cin >> temp, v.push_back(temp);
    rotateFunc(v, k);
    for (int i = 0; i < m; i++)
    {
        cout << v[i] << " ";
    }
}