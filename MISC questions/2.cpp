#include<bits/stdc++.h>
using namespace std;

void permutations(string s, int l, int r)
{
    if(l == r)
    {
        cout<<s<<endl;
        return;
    }
    else 
    {
        for(int i=l; i<=r; i++)
        {
            swap(s[l],s[i]);
            permutations(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}
int main()
{
    string a;
    int n;
    cin >> n;
    cin>>a;
    permutations(a,0,n-1);
}