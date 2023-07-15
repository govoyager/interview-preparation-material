#include<bits/stdc++.h>
const int n = 10e6+3;
using namespace std;
vector<int> graph[n];
int vis[n];

bool dfs(int s){
   vis[s] = true;
   for(auto i: graph[s]){
       if(!vis[i]){
           if(dfs(i))
           return true;
       }
       else if(i != s){
           return true;
       }
   } 
   return false;
}

void solve(int s){
    if(dfs(s))
    cout<<"Cycle is present";
    else
    {
        cout<<"No cycle is present";
    }
    
}

int main(){
    int N,m,u,v;
    cin>>N>>m;
    while (m--)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    solve(1);
    
}