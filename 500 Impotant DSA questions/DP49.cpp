#include <bits/stdc++.h>
using namespace std;
const int N = 10e6 + 3;
int dp[N];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    if (n == 1 or n == 2 or n == 0)
        cout << dp[n];
    else
    {
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n];
    }
}