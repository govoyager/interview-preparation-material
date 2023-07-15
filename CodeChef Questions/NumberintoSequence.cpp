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
    int a = n;
    unordered_map<int,int> m;
        while (n % 2 == 0)  
    {  
        if(m.find(2)==m.end()) m.insert(mp(2,1));
        else m[2]++;  
        n = n/2;  
    }  
  
    // n must be odd at this point. So we can skip  
    // one element (Note i = i +2)  
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        // While i divides n, print i and divide n  
        while (n % i == 0)  
        {  
            if(m.find(i)==m.end()) m.insert(mp(i,1));
            else m[i]++;
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        m.insert(mp(n,1));
    int maxi=-1;
    for(auto i :m){
        maxi = max({maxi,i.second});
    }
    cout<<maxi<<nl;
    if(maxi>1){
    for(auto i: m){
        if(i.second == maxi){
            forf(j,0,maxi-1) cout<<i.first<<" ";
            forf(k,0,maxi-1) a = a/i.first;
            cout<<a<<nl;
        }
    }
    }
    else
    {
        cout<<a<<nl;
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