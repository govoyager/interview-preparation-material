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

    int arr[n];
    map<int,int> m;
    set<int> s;
    forf(i,0,n){
        cin>>arr[i];
        if(m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;

        }
        else
        {
            m.insert(make_pair(arr[i],1));
        }
        
    }
    for(auto i : m){
        if(i.second == 1){
            s.insert(i.first);
        }

	}
    if(s.empty() == 1){
        cout<<-1<<nl;
    }
    else
    {
        forf(i,0,n){
            if(arr[i] == (*s.begin())){
                cout<<i+1<<nl;
                break;
            }
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