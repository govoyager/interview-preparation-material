#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       long long int n,result=10000000000;
        cin>>n;
       long long int arr[n];
        for(int i =0; i<n; i++) cin>>arr[i];
        sort(arr,arr+n);
        for (int i =0; i<n-1; i++)
        {
            result = std::min(result,arr[i+1]-arr[i]);
        }
        cout<<result<<"\n";
    }
}