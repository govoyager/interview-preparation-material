#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    unordered_set<int> se;
    unordered_map<char, int> m;
    for (auto i : s)
        m[i]++;

    int count = 0;
    for (auto i : m)
    {
        int temp = i.second;
        while (se.find(temp) != se.end())
        {
            temp -= 1;
            count += 1;
        }
        if (temp != 0)
            se.insert(temp);
    }
    return count;
}