#include <bits/stdc++.h>
using namespace std;

bool areIsomorphic(string str1, string str2)
{
    // Your code here
    if (str1.length() != str2.length())
        return false;
    unordered_map<char, int> m1, m2;
    for (auto i : str1)
    {
        m1[i]++;
    }
    for (auto i : str2)
    {
        m2[i]++;
    }

    for (int i = 0; i < str1.length(); i++)
    {
        if (m1[str1[i]] != m2[str2[i]])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << areIsomorphic(s1, s2);
}