#include <bits/stdc++.h>
using namespace std;

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
    ll n;
    cin >> n;
    if (n % 2050 == 0 && n >= 2050)
    {

        int count = 0;
        n = n / 2050;
        while (n > 0)
        {
            int last = n % 10;
            n = n / 10;
            count += last;
        }

        cout << count << nl;
    }
    else
    {
        cout << -1 << nl;
    }
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