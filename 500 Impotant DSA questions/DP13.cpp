#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 3;
int dp[N];

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j])
            {
                dp[i] = dp[j];
            }
        }
        dp[i]++;
        }
    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
}