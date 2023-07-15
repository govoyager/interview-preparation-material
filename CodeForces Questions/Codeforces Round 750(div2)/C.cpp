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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int j = n - 1;
    while (j >= i and s[i] == s[j])
    {
        i++;
        j--;
    }
    if (j < i)
    {
        cout << 0 << nl;
        return;
    }
    char c1 = s[i];
    char c2 = s[j];
    i = 0;
    j = n - 1;
    bool flag1 = 0;
    bool flag2 = 0;
    int count1 = 0;
    int count2 = 0;
    while (j >= i)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else if (s[i] == c1)
        {
            i++;
            count1 += 1;
        }
        else if (s[j] == c1)
        {
            j--;
            count1 += 1;
        }
        else
        {
            flag1 = 1;
            break;
        }
    }
    i = 0;
    j = n - 1;
    while (j >= i)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else if (s[i] == c2)
        {
            i++;
            count2 += 1;
        }
        else if (s[j] == c2)
        {
            j--;
            count2 += 1;
        }
        else
        {
            flag2 = 1;
            break;
        }
    }
    if (flag1 == 1 and flag2 == 1)
    {
        cout << -1 << nl;
    }
    else if (flag1 == 0 and flag2 == 0)
    {
        cout << min(count1, count2) << nl;
    }
    else if (flag1 == 0)
    {
        cout << count1 << nl;
    }
    else if (flag2 == 0)
    {
        cout << count2 << nl;
    }
    return;
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