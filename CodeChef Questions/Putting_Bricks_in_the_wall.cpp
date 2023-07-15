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
    char m[n][n];
    forf(i,0,n)
    {
        forf(j,0,n) cin>>m[i][j];
    }
    if(m[0][1] == '0' and m[1][0] == '0') 
    {
        if(m[n-2][n-1]=='0' and m[n-1][n-2] =='0')
        {
        cout<<'2'<<nl;
        cout<<n-1<<" "<<n<<nl;
        cout<<n<<" "<<n-1<<nl;
        }
        else if(m[n-2][n-1]=='1' and m[n-1][n-2] =='1')
        {
            cout<<"0"<<nl;
        }
        else if(m[n-2][n-1]=='1' and m[n-1][n-2] =='0')
        {
            cout<<"1"<<nl;
            cout<<n<<" "<<n-1<<nl;
        }
        else
        {
            cout<<"1"<<nl;
            cout<<n-1<<" "<<n<<nl;
        }
        
        

    }
    if(m[0][1] == '1' and m[1][0] == '1') 
    {
        if(m[n-2][n-1]=='1' and m[n-1][n-2] =='1')
        {
        cout<<'2'<<nl;
        cout<<n-1<<" "<<n<<nl;
        cout<<n<<" "<<n-1<<nl;
        }
        else if(m[n-2][n-1]=='0' and m[n-1][n-2] =='0')
        {
            cout<<"0"<<nl;
        }
        else if(m[n-2][n-1]=='1' and m[n-1][n-2] =='0')
        {
            cout<<"1"<<nl;
            cout<<n-1<<" "<<n<<nl;
        }
        else
        {
            cout<<"1"<<nl;
            cout<<n<<" "<<n-1<<nl;
        }
        
    }
    if(m[0][1] == '1' and m[1][0] == '0') 
    {
        if(m[n-2][n-1]=='1' and m[n-1][n-2] =='1')
        {
        cout<<"1"<<nl;
        cout<<1<<" "<<2<<nl;
        }
        else if(m[n-2][n-1]=='0' and m[n-1][n-2] =='0')
        {
            cout<<1<<nl;
            cout<<2<<" "<<1<<nl;
        }
        else if(m[n-2][n-1]=='1' and m[n-1][n-2] =='0')
        {
            cout<<"2"<<nl;
            cout<<1<<" "<<2<<nl;
            cout<<n<<" "<<n-1<<nl;
        }
        else
        {
            cout<<"2"<<nl;
            cout<<1<<" "<<2<<nl;
            cout<<n-1<<" "<<n<<nl;
        }
        
    }
    if(m[0][1] == '0' and m[1][0] == '1') 
    {
        if(m[n-2][n-1]=='1' and m[n-1][n-2] =='1')
        {
        cout<<"1"<<nl;
        cout<<2<<" "<<1<<nl;
        }
        else if(m[n-2][n-1]=='0' and m[n-1][n-2] =='0')
        {
            cout<<1<<nl;
            cout<<1<<" "<<2<<nl;
        }
        else if(m[n-2][n-1]=='1' and m[n-1][n-2] =='0')
        {
            cout<<"2"<<nl;
            cout<<2<<" "<<1<<nl;
            cout<<n<<" "<<n-1<<nl;
        }
        else
        {
            cout<<"2"<<nl;
            cout<<2<<" "<<1<<nl;
            cout<<n-1<<" "<<n<<nl;
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
	
	cout << getCurrentTime() << endl;
	return 0;
}