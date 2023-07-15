#include <bits/stdc++.h>
using namespace std;

int numTimesAllBlue(vector<int> &light)
{
    long long int sum = 0;
    long long int counter = 0;
    int ans = 0;
    for (auto i : light)
    {
        counter += 1;
        sum += i;
        long long int temp = ((counter + 1) * counter);
        temp = temp / 2;
        if (sum == temp)
        {
            ans += 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(3);
    v.push_back(5);
    cout << numTimesAllBlue(v);
}