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
    int n,d,flag =0;
    cin>>n;
    d = n % 10;
    if(n<10) flag=1;
    else if(n<100) flag=2;
    else if(n<1000) flag=3;
    else if (n<10000) flag=4;

    switch (flag)
    {
    case 1:
        cout<<10*(d-1) + 1<<nl;
        break;
    case 2:
        cout<<10*(d-1) + 3<<nl;
        break;
    case 3:
        cout<<10*(d-1) + 6<<nl;
        break;
    case 4:
        cout<<10*(d-1) + 10<<nl;
        break;
    default:
        break;
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