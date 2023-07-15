#include <bits/stdc++.h>
using namespace std;

void multiply(int mat[2][2],int M[2][2]){
    int x = mat[0][0] * M[0][0] + mat[0][1] * M[1][0];
    int y = mat[0][0] * M[0][1] + mat[0][1] * M[1][1];
    int z = mat[1][0] * M[0][0] + mat[1][1] * M[1][0];
    int w = mat[1][0] * M[0][1] + mat[1][1] * M[1][1];
     
    mat[0][0] = x;
    mat[0][1] = y;
    mat[1][0] = z;
    mat[1][1] = w;
}


void solve(int m[2][2], int n){
    if(n == 1 or n == 0)
    return;
    solve(m,n/2);
    multiply(m,m);
    int mat[2][2] = {{1,1},{1,0}}; 
    if(n%2 == 1){
        multiply(m,mat);
    }

}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    if(n == 0)
    return 0;
    if(n == 1){
        cout<<1;
        return 0;
    }
    int m[2][2] = {{1,1},{1,0}};
    solve(m,n);
    cout<<m[0][1];
}



