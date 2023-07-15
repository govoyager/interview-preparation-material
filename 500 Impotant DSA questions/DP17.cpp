#include <bits/stdc++.h>
using namespace std;
const int N = 10e3 + 6;
int dp[N][N];

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    dp[0][0] = 0;
    int n = str1.length(), m = str2.length();
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i] == str2[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    cout << dp[n][m];
}