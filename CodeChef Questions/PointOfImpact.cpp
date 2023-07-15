#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << (x) << endl;

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k,x,y;
        cin>>n>>k>>x>>y;
        k = k%4;
        if(x == y) 
        {
            cout<<n<<" "<<n<<endl;
        }
        else if(x>y)
        {
        if( k ==1) cout<<n<<" "<<y-x+n<<"\n";
        if(k == 2) cout<<n-x+y<<" "<<n<<"\n";
        if(k == 3) cout<<0<<" "<<x-y<<"\n";
        if(k == 0) cout<<x-y<<" "<<0<<"\n";
        }   
        else
        {
            if(k == 1) cout<<x-y+n<<" "<<n<<"\n";
            if(k == 2) cout<<n<<" "<<n-y+x<<"\n";
            if(k == 3) cout<<y-x<<" "<<0<<"\n";
            if(k == 0) cout<<0<<" "<<y-x<<"\n";
        }
        
    }
}
