#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a=9;
        set<int> s;
        cin>>n;
        if(n<10) cout<<n<<endl;
        else if(n>45) cout<<"-1"<<endl;
        else
        {
            while( a>0 && n>0)
            {
                if(n<10 && s.find(n) == s.end()) s.insert(n), n = 0;
                else{
                
                s.insert(a);
                n = n-a;
                a = a-1;
                }
            }
            for(auto i : s) cout<<i;
            cout<<endl;
            
        }

        
    }
}