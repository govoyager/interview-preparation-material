#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
       long long int n,d,flag=1,remain=0,k,qs=0;
        cin>>n>>k;
        d=n;
        int a[n];
        for(int i =0; i<n;i++) cin>>a[i];

        for(int j = 0 ; j<n;j++)
        {
            qs = remain + a[j];
            remain = qs - k;
            if (qs<k)
            {
                cout<<j+1<<"\n";
                flag = 0;
                break;
            }
            

                    
        }

        if (flag == 1) cout<< d + floor(qs/k)<<"\n";
    
        

     
    }
}