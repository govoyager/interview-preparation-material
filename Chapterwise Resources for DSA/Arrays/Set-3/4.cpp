#include <bits/stdc++.h>
using namespace std;

int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
{
    int dist1 = 0, dist2 = 0;
    if (start > destination)
    {
        swap(start, destination);
    }
    for (int i = start; i < distance.size(); i++)
    {
        if (i == destination)
        {
            break;
        }
        else
        {
            dist1 += distance[i];
        }
    }
    for (int i = start - 1; i >= 0; i--)
    {
        dist2 += distance[i];
    }
    for (int i = destination; i < distance.size(); i++)
    {
        dist2 += distance[i];
    }
    if (dist1 < dist2)
        return dist1;
    return dist2;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout << distanceBetweenBusStops(v, 0, 4);
}