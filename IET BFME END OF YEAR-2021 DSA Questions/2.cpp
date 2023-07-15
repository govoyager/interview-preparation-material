// A simple representation of graph using STL,
// for the purpose of competitive programming
#include<bits/stdc++.h>
using namespace std;
vector<int> e;
 
// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    e.push_back(u);
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}
 
// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}
 
// Driver code
int main()
{
    int M;
    int V;
    cin>>V>>M;
 
    // The below line may not work on all
    // compilers.  If it does not work on
    // your compiler, please replace it with
    // following
     vector<int> *adj = new vector<int>[V];
    //vector<int> adj[V];
 
    // Vertex numbers should be from 0 to 4
    for(int i =0;i<M;i++){
        int a,b;
        cin>>a>>b;
        addEdge(adj,a-1,b-1);
    }
    DFS(adj,V);
    int m = e.size()-1;
    if(m == V-1)
    cout<<0;
    else
    {
        cout<<V-1-m;
    }
    
    return 0;
}