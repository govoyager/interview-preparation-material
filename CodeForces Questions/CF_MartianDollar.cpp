#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;
    int maxi =b;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)
    {
    
        int m = *min_element(arr,arr+i);
        
        int a =((b/m)*(arr[i])+(b%m));
        
        if(maxi<a)
        {
            maxi = (b/m)*(arr[i])+(b%m);

        }
    }
    cout<<maxi;

}
