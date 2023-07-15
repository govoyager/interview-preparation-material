#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int minmum = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] <= minmum)
        {
            ans = max(0, ans);
            minmum = prices[i];
        }
        else
        {
            ans = max(ans, prices[i] - minmum);
        }
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(6);
    v.push_back(4);
    cout << maxProfit(v);
}