#include <bits/stdc++.h>
using namespace std;

vector<int> constructArray(int n, int k)
{
    vector<int> solution;
    int i = 1, j = n;
    int flag = 1;
    while (i < j && k > 0)
    {
        solution.push_back(i);
        i += 1;
        k -= 1;
        flag = 1;
        if (k < 1)
            break;
        solution.push_back(j);
        j -= 1;
        k -= 1;
        flag = 2;
    }
    if (flag == 1)
    {
        while (i <= j)
        {
            solution.push_back(i);
            i += 1;
        }
    }
    if (flag == 2)
    {
        while (i <= j)
        {
            solution.push_back(j);
            j -= 1;
        }
    }
    return solution;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> solution;
    solution = constructArray(n, k);
    for (auto i : solution)
    {
        cout << i << " ";
    }
}