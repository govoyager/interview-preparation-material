#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    cout<<pentagonal(n);
    



}

int pentagonal(int n){
    if(n == 1) return 1;
    return pentagonal(n-1) + (n-1)*5;
}