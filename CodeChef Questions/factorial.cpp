#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


int arr[100000];



int factorial(int i)
{
    if (i < 2)
    return 1;
    if (arr[i] != -1)
    return arr[i];
    return arr[i] =(factorial(i-1)%mod)*(i%mod)%mod;

}
int main()
{
    int t,i;
    cin>>t;
    memset(arr,-1, sizeof(arr));
    arr[0] = arr[1] = 1;
    while(t--)
    {
        cin>>i;
        
        cout<<factorial(i)<<endl;
    }

}