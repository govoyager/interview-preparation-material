#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (target == matrix[i][0])
        {
            return true;
        }
        else if (target < matrix[i][0] and i > 0)
        {
            for (int j = 0; j < matrix[i - 1].size(); j++)
            {
                if (matrix[i - 1][j] == target)
                {
                    return true;
                }
            }
        }
    }
    for (int i = 0; i < matrix[0].size(); i++)
    {
        if (target == matrix[matrix.size() - 1][i])
        {
            return true;
        }
    }
    return false;
}
