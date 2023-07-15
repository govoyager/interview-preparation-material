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
    int n, w, r;
    cin >> n >> w >> r;
    map<int, int> m;
    forf(i, 0, n)
    {
        int a;
        cin >> a;
        if (m.find(a) != m.end())
        {
            m[a] += 1;
        }
        else
        {
            m[a] = 1;
        }
    }
    if (r >= w)
    {
        cout << "YES" << nl;
    }
    else
    {
        int flag = 0;
        int d = w - r;
        for (auto i : m)
        {
            if (i.second > 1)
            {
                if (i.second % 2 == 0)
                {
                    d = d - (i.first * i.second);
                }
                else
                {
                    d = d - (i.first * (i.second - 1));
                }
            }
            if (d <= 0)
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