#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_set<int> s;
    s.insert(sum);
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(s.find(sum) == s.end())
        {
            s.insert(sum);
        }
        else
        {
            cout<<"TRUE";
            return 0;
        }

        
    }
    cout<<"FALSE";
    return 0;
}