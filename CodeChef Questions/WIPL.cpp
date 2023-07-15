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
    int n,k,sum1=0,sum2=0,count=0;
    cin>>n>>k;
    int arr[n];
    forf(i,0,n)cin>>arr[i];
    sort(arr,arr+n);
    int sum = (accumulate(arr,arr+n,0));
    if(sum<2*k)
    {
        cout<<-1<<nl;
    }
    else 
    {
    for(int i = n-1; i>=0;)
    {
        if(sum1<k && sum2<k)
        {
            if(sum1<sum2)
            {
                sum1 = sum1+arr[i];
                count = count +1;
                i= i-1;
            }
            else
            {
                sum2 += arr[i];
                i -= 1;
                count += 1;
            }
            
        }
        else
        {
            if(sum1<k)
            {
                sum1 += arr[i];
                i -= 1;
                count += 1;
            }
            else
            {
                sum2 += arr[i];
                i -= 1;
                count +=1;
            }
        }
        

        if(sum1>=k && sum2>=k)
        {
            break;
        }
        debug(count);

    }
    if(sum1>=k && sum2>=k)
    {
    cout<<count<<nl;
    }
    else
    {
        
        cout<<-1<<nl;
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