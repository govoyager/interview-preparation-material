#include <bits/stdc++.h>
using namespace std;

vector<int> sumZero(int n)
{
    vector<int> soln;
    int k = n / 2;
    int i = -1 * k;
    if (n % 2)
        soln.push_back(0);
    while (k >= i)
    {
        if (k != 0)
            soln.push_back(k);
        k -= 1;
    }
    return soln;
}

int main()
{
    int n;
    cin >> n;
    vector<int> solution = sumZero(n);
    for (auto i : solution)
        cout << i << " ";
}