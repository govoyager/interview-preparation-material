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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    vector<pair<int, int>> res;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            pq.push(make_pair(arr[i], i));
        }
    }
    while (!pq.empty())
    {
        auto first = pq.top();

        pq.pop();
        if (!pq.empty())
        {
            auto second = pq.top();
            pq.pop();
            count += 1;
            res.push_back(make_pair(first.second + 1, second.second + 1));
            first.first -= 1;
            second.first -= 1;
            if (first.first != 0)
            {
                pq.push(first);
            }
            if (second.first != 0)
            {
                pq.push(second);
            }
        }
        else
        {
            break;
        }
    }
    cout << count << nl;
    for (int i = 0; i < count; i++)
    {
        cout << res[i].first << " " << res[i].second << endl;
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