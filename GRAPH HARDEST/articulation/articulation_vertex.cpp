#include<bits/stdc++.h>
using namespace std;
int n, m, timer=0;
vector<vector<int>>adj;
vector<int>disc, low;
vector<bool>vis, isarti;
void dfs(int node, int parent){
      vis[node]=true;
      disc[node]=low[node]=++timer;
      int numchild = 0;
      for(auto ch:adj[node]){
            if(!vis[ch]){
                  numchild++;
                  dfs(ch, node);
                  low[node]= min(low[node],low[ch]);
                  if(parent != -1 &&low[ch] >= disc[node]){
                        isarti[node] = true;
                  } 
            } 
            else if(ch != parent){
                  low[node] = min(low[node], disc[ch]);
            }
      }
      if (parent == -1 && numchild > 1){
            isarti[node ]= true;
      }
}

signed main(){
     cin >>n >> m;
     adj.resize(n+1);
     disc.resize(n+1,-1);
     low.resize(n+1, -1);
     vis.resize(n+1, false);
     isarti.resize(n+1, false);
     for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
     }
     dfs(1, -1);
     for(int i=1;i<=n;i++){
      if(isarti[i])cout<<i<<" ";
     }
     return 0;

}