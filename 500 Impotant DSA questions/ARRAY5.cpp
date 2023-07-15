#include <bits/stdc++.h> 

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i]) == m.end())
        {
            m[arr[i]] = 1;
        }
        else
        {
            cout<<"The duplicate element is "<<arr[i];
        }
        
    }
}