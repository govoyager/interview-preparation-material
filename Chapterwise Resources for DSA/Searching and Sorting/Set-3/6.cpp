#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0, j = m - 1;

    while (i < n and j >= 0)
    {
        // cout<<matrix[i][j]<<endl;
        if (matrix[i][j] == target)
        {
            return true;
        }
        else if (matrix[i][j] < target)
        {
            i += 1;
        }
        else if (matrix[i][j] > target)
        {
            j -= 1;
        }
    }
    return false;
}