#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#define MOD (1000000000 + 7)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define print(vec, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << vec[i] << " ";   \
    cout << endl;
#define forf(i, a, b) for (int i = (a); i < (b); i++)
#define forr(i, a, b) for (int i = (a); i > (b); i--)
#define input(vec, N)             \
    for (int i = 0; i < (N); i++) \
        cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;

// template starts
typedef long long int ll;
#define int ll

void solve()
{
    int n;
    cin >> n;
    vector<int> arr, sortedarr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.pb(temp);
        sortedarr.pb(temp);
    }
    sort(all(sortedarr));
    vector<int> ls, rs;
    for (int i = n - 1; i >= 0; i--)
    {
        int element = sortedarr[i];
        int j = 0;
        for (j; j < n; j++)
        {
            if (arr[j] == element)
            {
                break;
            }
        }
        if (j != i)
        {
            ls.pb(j + 1);
            rs.push_back(i + 1);
        }
        for (int k = j + 1; k <= i; k++)
        {
            arr[k - 1] = arr[k];
        }
        arr[i] = element;
    }
    int m = ls.size();
    cout << m << endl;
    for (int i = 0; i < m; i++)
    {
        cout << ls[i] << " " << rs[i] << " 1" << endl;
    }
    return;
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //startTime = clock();
    int T;
    cin >> T;
    //T = 1;
    while (T--)
    {
        solve();
    }

    //cout << getCurrentTime() << endl;
    return 0;
}