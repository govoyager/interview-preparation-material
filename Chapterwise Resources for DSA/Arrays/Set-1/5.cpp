#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int product = 1;
    vector<int> solution;
    for (auto i : nums)
        product *= i;
    int zero_count = 0;
    if (product == 0)
    {
        for (auto i : nums)
        {
            i == 0 ? zero_count += 1 : zero_count = zero_count;
        }
        //cout<<"zero_count = "<<zero_count<<endl;
        if (zero_count > 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                solution.push_back(0);
            }
            return solution;
        }
        int p = 1;
        for (auto i : nums)
            if (i != 0)
                p *= i;
        //cout<<"p = "<<p<<endl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                solution.push_back(p);
            }
            else
            {
                solution.push_back(0);
            }
        }
        return solution;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        solution.push_back(product / nums[i]);
    }
    return solution;
}

int main()
{
    int n;
    vector<int> v, solution;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    solution = productExceptSelf(v);
    for (auto i : solution)
    {
        cout << i << " ";
    }
}
