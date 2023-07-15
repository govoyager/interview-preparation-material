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
    int m = -1,flag =0;
    forf(i,0,n){

    cin>>arr[i];
    m = max({m,arr[i]});
    }
    
    forf(i,0,n){
        if(i == 0 ){
            if ( arr[i] == m && ( arr[i+1] < m ))
            {
                flag = 1, cout<<i+1<<nl;
                break;
            }
        }
        else if ( i == n-1){
            if( arr[i] == m && (arr[i-1] < m)){
                flag = 1, cout<<i+1<<nl;
                break;
            }
        }
        else if( arr[i] == m && ( arr[i-1] < m || arr[i+1] < m)){
            flag =1,cout<<i+1<<nl;
            break;
        }


    }
    if( flag == 0 ){
        cout<<-1<<nl;
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