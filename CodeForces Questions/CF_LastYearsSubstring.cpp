#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char arr[n];
        cin>>arr;
        
        if(arr[n-1] == '0' && arr[n-2] == '2' && arr[n-3] == '0' && arr[n-4] == '2') cout<<"YES\n";
        else if(arr[0] == '2' && arr[n-1] == '0' && arr[n-2] == '2' && arr[n-3] == '0' ) cout<<"YES\n";
        else if(arr[0] == '2' && arr[1] == '0' && arr[n-1] == '0' && arr[n-2] == '2') cout<<"YES\n";
        else if(arr[0] == '2' && arr[1] == '0' && arr[2] == '2' && arr[n-1] == '0') cout<<"YES\n";
        else if(arr[0] == '2' && arr[1] == '0' && arr[2] == '2' &&arr[3]=='0' ) cout<<"YES\n";
        else cout<<"NO\n";
    }
}