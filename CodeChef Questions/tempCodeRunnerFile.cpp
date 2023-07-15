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
    int n,a;
    cin>>n;
    vector<int> v;
    forf(i,0,n) cin>>a , v.pb(a);
    sort(all(v));
    if(n == 1) cout<<v[0]<<nl;
    else if (n ==2)
    {
        cout<<v[1]<<nl;
    }
    else
    {
        int sum1=0,sum2=0;
        while(!v.empty())
        {
            if(sum1<sum2)
            {
            sum1 += v.back();
            v.pop_back();
            if(!v.empty()){
            sum2 += v.back();
            v.pop_back();
            }}
            else
            {
                sum2 += v.back();
                v.pop_back();
                if(!v.empty()){
                    sum1 += v.back();
                    v.pop_back();
                } 
            }
        }
        cout<<max({sum1,sum2})<<nl;
    }
    

}


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	
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