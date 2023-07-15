/*
 * N Queens Problem
 * Solution using backtracking
 */

#include <bits/stdc++.h>
using namespace std;

#define N 8
void printTheSolution(char mat[][N]);

void nQueens(char mat[][N], int r)
{
    if (r == N)
    {
        printTheSolution(mat);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        bool isSafe = true;
        for (int j = 0; j < r; j++)
        {
            if (mat[j][i] == 'Q')
            {
                isSafe = false;
            }
        }
        for (int j = r, k = i; j >= 0 and k >= 0; j--, k--)
        {
            if (mat[j][k] == 'Q')
            {
                isSafe = false;
            }
        }
        for (int j = r, k = i; j >= 0 and k < N; j--, k++)
        {
            if (mat[j][k] == 'Q')
            {
                isSafe = false;
            }
        }
        if (isSafe)
        {
            mat[r][i] = 'Q';
            nQueens(mat, r + 1);
            mat[r][i] = '-';
        }
    }
}


void printTheSolution(char  mat[][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

int main()
{
    char mat[N][N];
    memset(mat, '-', sizeof(mat));
    nQueens(mat, 0);
    return 0;
}
