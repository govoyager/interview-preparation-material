#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cout << "Enter number:";
    cin >> n;
    if (n == 1)
    {
        cout << "Not a prime";
        return 0;
    }
    if (n == 2)
    {
        cout << "Prime";
        return 0;
    }
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not a prime";
            return 0;
        }
    }
    cout << "Prime";
    return 0;
}