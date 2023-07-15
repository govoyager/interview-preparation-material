#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<int> graph[N];
bool vis[N];

void dfs(int s)
{
    vis[s] = true;
    for (auto i : graph[s])
    {
        if (!vis[i])
            dfs(i);
    }
}

int main()
{
    int n, e, u, v;
    cin >> v >> e;
    while (e--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        // Comment this line for a directed graph.
        graph[v].push_back(u);
    }
    int source, dest;
    cin >> source >> dest;
    dfs(source);
    if (vis[dest])
        cout << "Path exists";
    else
    {
        cout << "Path does not exist";
    }
}