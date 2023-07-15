#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    unordered_multimap<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    m.insert(make_pair(0,-1));
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
        if(m.find(sum) != m.end())
        {
            auto it = m.find(sum);
            while(it != m.end() && it->first == sum)
            {
                cout<<"index from "<<it->second+1<<"to "<<i<<endl; 
                it++;
            }
        }
        m.insert(make_pair(sum,i));
    }

}