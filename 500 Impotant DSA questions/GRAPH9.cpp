#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
vector<int> graph[N];
bool vis[N];
int color[N];

bool dfs(int s)
{
    for (auto i : graph[s])
    {
        if (!vis[i])
        {
            vis[i] = true;
            color[i] = !color[s];
            if (!dfs(i))
                return false;
        }
        else if (color[i] == color[s])
        {
            return false;
        }
    }
    return true;
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
    int source = 1;
    vis[source] = true;
    color[source] = 0;
    if (dfs(source))
        cout << "Graph is bipartite";
    else
    {
        cout << "Graph is not bipartite";
    }
}