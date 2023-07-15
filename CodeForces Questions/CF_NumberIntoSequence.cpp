#include <bits/stdc++.h>
using namespace std;

#define MOD (1000000000+7)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define print(vec,l,r) for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define forf(i,a,b) for(int i = (a); i < (b); i++)
#define forr(i,a,b) for(int i = (a); i > (b); i--)
#define input(vec,N) for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x) cerr << #x << " = " << (x) << endl;

// template starts
typedef long long int ll;
#define int ll

void solve(){
    int n;
    cin>>n;
    int a =n;
   unordered_map<int,int> m;
    for(int i =2; i<=n;i++)
    {
        if(n%i == 0)
        {
            if(m.find(i) == m.end())
            {
                m.insert(mp(i,1));
                n = n/i;
                i = i-1;
            }
            else
            {
                m[i]++;
                n = n/i;
                i = i-1;
            }
            
        }
    }
    
    for(auto i :m)
    {
        cout<<i.first<<" "<<i.second<<nl;
    }

	}


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	//startTime = clock();
	
	int T;
	cin >> T;
	//T = 1;
	while(T--){
		solve();
	}
	
	//cout << getCurrentTime() << endl;
	return 0;
}