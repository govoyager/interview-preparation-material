#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,k,n,flag=0;
        cin>>x>>y>>k>>n;
        int p[n],c[n];
        for(int i =0; i<n;i++) cin>>p[i]>>c[i];
        if(x>y)
        {
            for(int i=0; i<n; i++)
            {
            
                
                if(x-y<=p[i] && c[i]<=k) 
                {
                    cout<<"LuckyChef\n";
                    flag =1;
                    break;
                }
            }   
            if(flag==0) cout<<"UnluckyChef\n";
        }
        else
        {
            cout<<"LuckyChef\n";
            
        }
    }
}