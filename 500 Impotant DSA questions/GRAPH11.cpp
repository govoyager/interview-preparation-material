#include <bits/stdc++.h>
using namespace std;
const int n = 10e6 + 3;
vector<int> graph[n];
bool vis[n];
int departure_time[n];
int time1;

void dfs(int s)
{
    vis[s] = true;
    time1++;
    for (auto i : graph[s])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    departure_time[s] = time1;
    time1++;
}

bool comparator(int a, int b)
{
    return departure_time[a] > departure_time[b];
}

void topological_sort(int N)
{
    int v[N];
    iota(v, v + N, 0);
    sort(v, v + N, comparator);
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int N, m, u, v;
    cin >> N >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    topological_sort(N);
}