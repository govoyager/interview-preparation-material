#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    int count =0;
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0) count += 1;
    }
    for(int i=0;i<n;i++)
    {
        if(count>0) arr[i] =0,count--;
        else arr[i] =1;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}