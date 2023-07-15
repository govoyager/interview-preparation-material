#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    // your code here
    int n = s.length();
    if (n % 2)
        return -1;
    int open_brackets = 0, close_brackets = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{')
        {
            open_brackets += 1;
        }
        if (s[i] == '}')
        {
            if (open_brackets > 0)
            {
                open_brackets -= 1;
            }
            else
            {
                close_brackets += 1;
            }
        }
    }
    if (close_brackets % 2 == 0 and open_brackets % 2 == 0)
    {
        return (close_brackets + open_brackets) / 2;
    }
    return (close_brackets + open_brackets) / 2 + 1;
}

int main()
{
    string s;
    cin >> s;
    cout << countRev(s);
}