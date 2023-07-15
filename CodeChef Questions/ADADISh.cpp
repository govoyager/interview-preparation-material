#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define nl '\n'
#define all(x) x.begin(), x.end()
#define forf(i,a,b) for(int i = (a); i < (b); i++)
typedef long long int ll;
#define int ll

int findmin(vector<int> v, int i, int sumcalc, int sum)
{
    if (i == 0) return max({sumcalc, sum - sumcalc});

    return(min({findmin(v,i-1,sumcalc+v[i-1],sum),findmin(v,i-1,sumcalc,sum)}));
}
void solve(){
    int n,a,sum=0;
    cin>>n;
    vector<int> v;
    forf(i,0,n) cin>>a , v.pb(a);
    sort(all(v));
    sum = accumulate(all(v),0);
    if(n == 1) cout<<v[0]<<nl;
    else if (n ==2)
    {
        cout<<v[1]<<nl;
    }
    else
    {
        cout<<findmin(v,n,0,sum)<<nl;;
    }


    

}

signed main(){
	int T;
	cin >> T;
	
	while(T--){
		solve();
	}
	return 0;
}