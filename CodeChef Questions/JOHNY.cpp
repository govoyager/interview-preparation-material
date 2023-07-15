#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int n,a,k;
        cin>>n;
        long long int arr[n];
        for(int i =0; i<n; i++) cin>>arr[i];
        cin>>k;
        a = arr[k-1];
        sort(arr,arr+n);
        for(int i = 0; i<n; i++) 
        {
            if (a == arr[i])
            {
                cout<<i+1<<"\n";
                break;
            }
        }
     }
    
}