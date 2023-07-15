#include <bits/stdc++.h>
using namespace std;

// template starts
typedef long long int ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> arr;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(make_pair(temp, i));
        }
        sort(arr.begin(), arr.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i].first * arr[j].first > 2 * n)
                {
                    break;
                }
                else if ((arr[i].first * arr[j].first) == (arr[i].second + arr[j].second))
                {
                    count += 1;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}