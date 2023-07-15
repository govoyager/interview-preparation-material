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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count1 = 0;
    int count0 = 0;

    if (n == 1)
    {
        if (s[0] == '1')
            cout << "YES" << nl;
        else
        {
            cout << "NO" << nl;
        }
    }
    else
    {
        int flag = 0;
        if (s[0] == '1')
        {
            count1 += 1;
        }
        else
        {
            count0 += 1;
        }

        for (int i = 1 ; i < n; i++)
        {
            if (s[i] == '1')
            {
                count1 += 1;
            }
            else
            {
                count0 += 1;
            }
            if (count1 >= count0)
            {
                cout << "YES" << nl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "NO" << nl;
        }
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