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

int count_same_digit(int L, int R)
{
    int tmp = 0, ans = 0;
  
    // length of R
    int n = log10(R) + 1;
  
    for (int i = 0; i < n; i++) {
  
        // tmp has all digits as 1
        tmp = tmp * 10 + 1;
  
        // For each multiple
        // of tmp in range 1 to 9,
        // check if it present
        // in range [L, R]
        for (int j = 1; j <= 9; j++) {
  
            if (L <= (tmp * j)
                && (tmp * j) <= R) {
  
                // Increment the required count
                ans++;
            }
        }
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    cout<<count_same_digit(1,n)<<nl;
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