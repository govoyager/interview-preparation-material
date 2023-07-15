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
    vector<int> arr(n), ans(n);
    input(arr, n);
    if (n % 2 == 0)
    {
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            if ((arr[i] < 0 and arr[j] < 0) or (arr[i] > 0 and arr[j] > 0))
            {
                ans[i] = -1 * arr[j];
                ans[j] = arr[i];
            }
            else if (arr[i] < 0)
            {
                ans[i] = arr[j];
                ans[j] = -1 * arr[i];
            }
            else if (arr[j] < 0)
            {
                ans[i] = -1 * arr[j];
                ans[j] = arr[i];
            }
            i++;
            j--;
        }
    }
    else
    {
        int i = 0;
        int j = n - 1;
        while (i < j - 2)
        {
            if ((arr[i] < 0 and arr[j] < 0) or (arr[i] > 0 and arr[j] > 0))
            {
                ans[i] = -1 * arr[j];
                ans[j] = arr[i];
            }
            else if (arr[i] < 0)
            {
                ans[i] = arr[j];
                ans[j] = -1 * arr[i];
            }
            else if (arr[j] < 0)
            {
                ans[i] = -1 * arr[j];
                ans[j] = arr[i];
            }
            i++;
            j--;
        }
        int a = arr[i];
        int b = arr[i + 1];
        int c = arr[i + 2];
        if ((a + b) != 0)
        {
            ans[i] = -c;
            ans[i + 1] = -c;
            ans[i + 2] = a + b;
        }
        else if ((c + b) != 0)
        {
            ans[i] = b + c;
            ans[i + 1] = -a;
            ans[i + 2] = -a;
        }
        else if ((a + c) != 0)
        {
            ans[i] = -b;
            ans[i + 1] = a + c;
            ans[i + 2] = -b;
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}