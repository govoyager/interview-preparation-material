#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int g,n,i,q,h,t;
        cin>>g;
        while(g--)
        {
            cin>>i>>n>>q;
            if (n%2==0) cout<<n/2<<"\n";
            else
            {
                if(q==i )
                {
                    cout<<n/2<<"\n";
                }
                else
                {
                    cout<<n/2+1<<"\n";
                }
                
            }
            
                
            
        }
    }
}