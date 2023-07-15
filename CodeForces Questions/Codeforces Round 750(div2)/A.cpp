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

long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

/*<------------ IF WA OCCURS ------------->
 * Look for overflow errors
 * Think about corner casses once again
 * Include cout<<fixed<<setprecision(11); in main  for printing decimals
 * Use 0LL instead of 0
 * Do endl after testcase
 *
 * <----------- IF TLE OCCURS ------------>
 * Use ordered map if unordered map blows up
 * Look at i++ and i-- in for loops
 * check breaking cases of loops
 * calculate time with question constraints
 */

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a % 2 == 0 and b % 2 == 0 and c % 2 == 0)
    {
        cout << 0 << nl;
        return;
    }
    if (a % 2 == 1 and b % 2 == 1 and c % 2 == 1)
    {
        cout << 0 << nl;
        return;
    }
    if (a % 2 == 1 and b % 2 == 0 and c % 2 == 0)
    {
        cout << 1 << nl;
    }
    if (a % 2 == 1 and b % 2 == 1 and c % 2 == 0)
    {
        cout << 1 << nl;
    }
    if (a % 2 == 0 and b % 2 == 1 and c % 2 == 1)
    {
        cout << 1 << nl;
    }
    if (a % 2 == 0 and b % 2 == 1 and c % 2 == 0)
    {
        cout << 0 << nl;
    }
    if (a % 2 == 0 and b % 2 == 0 and c % 2 == 1)
    {
        cout << 1 << nl;
    }
    if (a % 2 == 1 and b % 2 == 0 and c % 2 == 1)
    {
        cout << 0 << nl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}