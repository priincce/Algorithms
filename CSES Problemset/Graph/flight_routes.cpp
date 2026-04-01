#include<bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<pair<int, int>>>adj;
vector<vector<int>>dist;
void solve(){
      cin>>n>>m>>k;
      adj.resize(n+1);
      dist.resize(n+1, vector<int>(k+1, INT_MAX));
      for(int i=0; i<m ; i++){
            int x, y, z;
            cin>>x>>y>>z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
      }
      
}
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
      return 0;
}