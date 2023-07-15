#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d,n,result,r=0,nr=0;
        cin>>n>>d;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) (arr[i]<=9 || arr[i]>=80)?r +=1:nr += 1;
        result = (r%d == 0?r/d:(r/d +1)) + (nr%d == 0?nr/d:(nr/d +1));
        cout<<result<<"\n";
    }
}