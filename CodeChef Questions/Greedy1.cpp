#include<bits/stdc++.h>
using namespace std;

bool sortv( pair<int,int> p1, pair<int,int>     p2)
{
    return (p1.second<=p2.second) ;
    }
int main()
{
    int n,k=0;
    set<int> s;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),sortv);
    s.insert(k);
    for(int i=0;i<n;i++)
    {
        if(v[k].second <= v[i].first)
        { 
        s.insert(i);
        k =i;
        }

    }
    for(auto i: s)
    {
        cout<<"{"<<v[i].first<<","<<v[i].second<<"}"<<endl;
    }

}