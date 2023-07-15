#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        if(n==k)
        {
            for(int i=0;i<n;i++) arr[i] = i+1;
        }
        else if(k <= n/2 )
        {
            int count =k;
            for(int i=0;i<n;i++)
            (count>0 && (i+1)%2 ==0)?arr[i] = i+1,count-=1:arr[i]= -(i+1);
        }
        else
        {
            int count1 = k - n/2;
            int count =k;
            for(int i=0;i<n;i++)
            (count>0 && (i+1)%2 ==0)?arr[i] = i+1,count-=1:arr[i]= -(i+1);
            for(int j=n-1;count1>0;j--)
            {
                if(arr[j]<0) arr[j] = arr[j]*(-1),count1 = count1 - 1;
            }
        }
        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<"\n"; 
        
    }
}