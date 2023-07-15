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
    int n, m;
    cin>>n>>m;
    int count =0;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.pb(temp);
    }
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        b.pb(temp);
    }
    int m1 = *max_element(a.begin(),a.end());
    int m2 = *max_element(b.begin(),b.end());
    int ele = max(m1,m2);
    //cout<<ele;
    for(int i = 1;i<=ele;i++){
        bool one = true, two = true;
        for(auto j:a){
            if(i%j != 0){
                one = false;
                break;
            }
        }
        for(auto j:b){
            if(j%i != 0){
                two = false;
                break;
            }
        }
        if(one and two)
            count += 1;
    }
    cout<<count;
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
	//cin >> T;
	T = 1;
	while (T--)
	{
		solve();
	}

	//cout << getCurrentTime() << endl;
	return 0;
}