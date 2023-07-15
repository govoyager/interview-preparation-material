#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,t,c,count=0;
    cin>>n>>t>>c;
    int arr[n+1],counter[n+1];
    counter[0]=0;
    for(int i=1; i<=n;i++)cin>>arr[i];
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i] > t)
        {
            s += 1;
            counter[i] = s;
        }
        else
        {
            counter[i] = s;
        }
        
    }
    for(int i=1;i<=n-c+1;i++)
    {
        if(counter[i+c-1]-counter[i-1] == 0)
        count += 1;
    }
    cout<<count;
}