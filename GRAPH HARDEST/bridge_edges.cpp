#include<bits/stdc++.h>
using namespace std;
int n, m, timer=0;
vector<vector<int>>adj;
vector<int>disc, low;
vector<bool>vis;
vector<pair<int, int>>bridges;
void dfs(int node, int parent){
      vis[node]=true;
      disc[node]=low[node]=++timer;
      int numchild = 0;
      for(auto ch:adj[node]){
            if(!vis[ch]){
                  numchild++;
                  dfs(ch, node);
                  low[node]= min(low[node],low[ch]);
                  if(low[ch] > disc[node]){
                        bridges.push_back({node, ch});
                  }
            } 
            else if(ch != parent){
                  low[node] = min(low[node], disc[ch]);
            }
      }
}

signed main(){
     cin >>n >> m;
     adj.resize(n+1);
     disc.resize(n+1,-1);
     low.resize(n+1, -1);
     vis.resize(n+1, false);
     for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     dfs(1, -1);
     for(auto [u, v]:bridges){
      cout<<u<<" "<<v<<endl;
     }
     return 0;

}