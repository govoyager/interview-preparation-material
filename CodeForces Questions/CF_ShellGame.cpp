#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int m[6][3];
    m[0][0] = 1;
    m[0][1] = 0;
    m[0][2] = 2;
    m[1][0] = 1;
    m[1][1] = 2;
    m[1][2] = 0;
    m[2][0] = 2;
    m[2][1] = 1;
    m[2][2] = 0;
    m[3][0] = 2;
    m[3][1] = 0;
    m[3][2] = 1;
    m[4][0] = 0;
    m[4][1] = 2;
    m[4][2] = 1;
    m[5][0] = 0;
    m[5][1] = 1;
    m[5][2] = 2;
    long long int n;
    long long int a;
    cin>>n;
    cin>>a;
    (n%6 == 0 && n>=6 )?n = 6:n=n%6;
    cout<<m[n-1][a];

}