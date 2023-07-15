#include <bits/stdc++.h>
using namespace std;

int binarySqrt(int n)
{
    if (n == 0 or n == 1)
        return n;
    int l = 1, r = n, ans;
    while (l <= r)
    {
        int m = (r + l) / 2;
        if (m * m == n)
            return m;
        if (m * m < n)
        {
            ans = m;
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << binarySqrt(n);
}