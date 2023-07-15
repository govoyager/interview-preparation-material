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
    int n,m,count=0,sum1=0,sum2=0,flag=1;
    cin>>n>>m;
    int a[n],b[m];
    forf(i,0,n) cin>>a[i];
    forf(i,0,m) cin>>b[i];
    sum1 = accumulate(a,a+n,sum1);
    sum2 = accumulate(b,b+m,sum2);
    if(sum1>sum2)
    {
        cout<<0<<nl;
    }
    else
    {
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=m-1,temp;
        while(sum2>=sum1)
        {
            if(i>=n) 
            {
                cout<<-1<<nl;
                return;
            }
            if(j<0)
            {
                cout<<-1<<nl;
                return;
            }
            temp = a[i];
            a[i] = b[j];
            b[j] = temp;
            count += 1;
            i++;
            j--;
            sum1 = accumulate(a,a+n,0);
            sum2 = accumulate(b,b+m,0);
            debug(sum1);
            debug(sum2);

        }
        cout<<count<<nl;
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