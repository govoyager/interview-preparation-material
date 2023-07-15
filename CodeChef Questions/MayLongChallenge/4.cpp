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
    string s[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }
    bool x_won = false;
    bool o_won = false;
    int count_x = 0, count_o = 0, empty = 0, winners = 0;
    for (int i = 0; i < 3; i++)
    {
        for (auto j : s[i])
        {
            if (j == 'X')
                count_x += 1;
            if (j == 'O')
                count_o += 1;
            if (j == '_')
                empty += 1;
        }
    }
    if (s[0][0] == s[1][1] and s[1][1] == s[2][2] and s[2][2] != '_')
    {
        winners++;
        s[0][0] == 'X' ? x_won = true : o_won = true;
    }
    if (s[0][2] == s[1][1] and s[1][1] == s[2][0] and s[2][0] != '_')
    {
        winners++;
        s[1][1] == 'X' ? x_won = true : o_won = true;
    }
    for (int i = 0; i < 3; i++)
    {
        if (s[i][0] == s[i][1] and s[i][1] == s[i][2] and s[i][2] != '_')
        {
            winners++;
            s[i][0] == 'X' ? x_won = true : o_won = true;
        }
        if (s[0][i] == s[1][i] and s[1][i] == s[2][i] and s[2][i] != '_')
        {
            winners++;
            s[0][i] == 'X' ? x_won = true : o_won= true;
        }
    }
    debug(winners);
    debug(count_o);
    debug(count_x);
    debug(x_won);
    debug(o_won);
    if (empty == 9)
    {
        cout << 2 << nl;
    }
    else if (winners == 2 and x_won and !o_won and count_x == 5)
    {
        cout << 1 << nl;
    }
    else if (winners > 1 or count_o > count_x or count_x > count_o + 1 or (x_won and count_x == count_o))
    {

        cout << 3 << nl;
    }
    else if (winners or empty == 0)
    {
        cout << 1 << nl;
    }
    else if (empty > 0 and winners == 0)
    {
        cout << 2 << nl;
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