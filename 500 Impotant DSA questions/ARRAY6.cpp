#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,lastindex=-1,len=0,sum=0,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> m;
    m[0]=-1;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(m.find(sum) == m.end())
        {
            m[sum]=i;
        }
        if(m.find(sum-s) != m.end() &&  len<i - m[sum-s])
        {
            len = i - m[sum-s];
            lastindex = i;
        }
    }
    
    cout<<"["<<lastindex-len +1+1<<","<<lastindex+1<<"]";
}