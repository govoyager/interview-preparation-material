//1) Print the elements of an array in the decreasing frequency if 2 numbers have same frequency then print the one which came first.
// Try to solve this problem use STL as much as you can.
#include<bits/stdc++.h>

using namespace std;

bool cmp( pair<int,pair<int,int>> a, pair<int,pair<int,int>> b )
{
    
    if (a.second.second != b.second.second)
        return (a.second.second >b.second.second);
    else
        return (a.second.first < b.second.first);
}


int main()
{
    unordered_map<int,pair<int,int>> m;
    int n;
    cin>>n;
    
    for(int i=0; i<n;i++ )
    {
        int a;
        cin>>a;
        if(m.find(a) != m.end())
        {
            m[a].second++;
            
        }
        else
        {
          m[a] = make_pair(i,1);
            
        }
        
    }
    vector<pair<int,pair<int,int>>> v;
    for(auto i : m)
    {
        v.push_back(make_pair(i.first,i.second));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i: v)
    {
        cout<<i.first<<" ";
    }   
}