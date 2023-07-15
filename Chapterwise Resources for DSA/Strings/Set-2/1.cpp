#include <bits/stdc++.h>
using namespace std;

bool ispar(string x)
{
    stack<char> s;
    for (auto i : x)
    {
        if (i == '[' or i == '{' or i == '(')
        {
            s.push(i);
        }
        else if (i == ']')
        {
            if (!s.empty() and s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (i == ')')
        {
            if (!s.empty() and s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
        else if (i == '}')
        {
            if (!s.empty() and s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << ispar(s);
}