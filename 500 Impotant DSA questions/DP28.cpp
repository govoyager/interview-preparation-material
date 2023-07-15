#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> temp, v.push_back(temp);
    int sum = accumulate(v.begin(), v.end(), 0);
    bool dp[n + 1][sum + 1];
    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    //cout<<"n = "<<n<<endl;
    for (int i = 1; i <= n; i++)
    {
        //cout << "i = " << i << endl;
        for (int j = 1; j < sum + 1; j++)
        {
            dp[i][j] = (dp[i - 1][j]);

            if (v[i - 1] <= j)
            {
                dp[i][j] |= dp[i - 1][j - v[i - 1]];
            }
            //cout<<"dp["<<i<<","<<j<<"]"<<"="<<dp[i][j]<<" ";
        }
        cout << endl;
    }
    int diff = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i])
        {
            diff = (sum - i) - i;
            break;
        }
    }
    cout << diff;
}