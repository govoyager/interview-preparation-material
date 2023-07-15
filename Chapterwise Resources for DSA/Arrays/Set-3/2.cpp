#include <bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int> &arr)
{
    unordered_map<int, int> m;
    for (auto i : arr)
    {
        if (m.find(2 * i) != m.end())
        {
            return true;
        }
        else if (i % 2 == 0 and (m.find(i / 2) != m.end()))
        {
            return true;
        }
        else
        {
            m[i]++;
        }
    }
    return false;
}

int main()
{
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(10);
    v.push_back(3);
    cout << checkIfExist(v);
}
