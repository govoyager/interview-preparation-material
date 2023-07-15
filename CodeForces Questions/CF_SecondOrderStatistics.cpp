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
	vector<int> vi;
    forf(i,0,T) 
    {
        int n;
        cin>>n;
        vi.push_back(n);
    }
    sort(vi.begin(),vi.end());
    int m;
    std::vector<int>::iterator ans;
    m = *min_element(vi.begin(),vi.end());
   ans = upper_bound(vi.begin(),vi.end(),m);
   if(ans == vi.end()) cout<<"NO"<<nl;
   else 
   {
   cout<<*ans<<nl; 
   }

	
	//cout << getCurrentTime() << endl;
	return 0;
}