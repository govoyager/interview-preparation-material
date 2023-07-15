//complexity is O(n) and break statement can be removed to print all posiblities. Works for duplicates also, doesn't work for negatives;
//One more solution with O(nlogn) is also possible;
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;
    unordered_map<int,int> m;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>sum;
    for(int i=0;i<n;i++)
    {
        if(m.find(sum-arr[i]) == m.end())
        {
            m[arr[i]] = i;
        }
        else
        {
            cout<<"Index found at "<<m[sum - arr[i]]<<" and "<<i;
            break;
            
        }
        
    }


}