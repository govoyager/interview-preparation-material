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
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    int lower = b - a - 1;
    if (a - 1 > lower)
    {
        cout << -1 << nl;
        return;
    }
    int maxn = b + lower - (a - 1);
    if (maxn & 1)
    {
        cout << -1 << nl;
        return;
    }
    if (c > maxn)
    {
        cout << -1 << endl;
        return;
    }
    ((c + maxn / 2) % maxn) == 0 ? cout << maxn << endl : cout << ((c + maxn / 2) % maxn) << endl;
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