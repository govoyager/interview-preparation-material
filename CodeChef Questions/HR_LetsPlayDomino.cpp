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
    int n,flag =1,count=0,count2=0;
    cin>>n;
    int f[n], s[n],f1[n],s1[n];
    forf(i,0,n) cin>>f[i]>>s[i];
    forf(i,0,n) f1[i] = f[i] , s1[i] = s[i];
    
    forf(i,0,n-1)
    {
        if ( f[i] == f[i+1] or s[i] == s[i+1]){}
        else
        {
            if( f[i] == s[i+1] or s[i] == f[i+1])
            {
                count = count +1;
                int t;
                t = f[i+1];
                f[i+1] = s[i+1];
                s[i+1] = t;
            }
            else
            {
                flag = 0;
                break;
            }
            
        }
        
    }
    forr(i,n-1,0)
    {
        if ( f1[i] == f1[i-1] or s1[i] == s1[i-1]){}
        else
        {
            
            if( f1[i] == s1[i-1] or s1[i] == f1[i-1])
            {
                
                count2 = count2 +1;
                int t;
                t = f1[i-1];
                f1[i-1] = s1[i-1];
                s1[i-1] = t;
            }
            else
            {
                flag = 0;
                break;
            }
            
        }
        
    }

    
    if(flag ==1 ) 
    {
        if(count<count2)
        {
            cout<<count<<nl;
        }
        else cout<<count2<<nl;
    }
    else cout<<"-1"<<nl;

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