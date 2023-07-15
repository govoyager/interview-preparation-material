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
    int n,count1=0,count2=0;
    cin>>n;
    
    string str;
    cin>>str;
    if(n<=2)
    { 
        cout<<"0"<<nl;
    }
    else 
    {
    forf(i,0,n-1)
    {
        
        if(str[i] == '1'  && str[i] == str[i+1]) count1 += 1;

    } 
    forf(i,0,n-1)
    {
        
        if(str[i] == '0'  && str[i] == str[i+1]) count2 += 1;

    }
    if(count1 == count2) cout<<count1<<nl;
    else if(count1 > count2)
    {
        cout<<count1<<nl;
    }
    else
    {
        cout<<count2<<nl;
    }
    
    
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