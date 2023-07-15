#include <bits/stdc++.h>
using namespace std;
const int N = 10e6 + 3;
int dp[N];

int main()
{
    int m, n;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j <= i)
            {
                dp[i] += dp[i - j];
            }
        }
        }
    cout << dp[n];
}