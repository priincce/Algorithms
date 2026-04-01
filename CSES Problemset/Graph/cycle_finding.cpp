#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Edge{
      int u;
      int v;
      int w;
};
int n, m;
vector<Edge>edges;

void solve(){
      cin>>n>>m;
      edges.resize(m);
      for(auto &e:edges){
            cin>>e.u>>e.v>>e.w;
      }
      vector<ll>dist(n+1, 0);
      vector<int>parent(n+1, -1);
      int x=-1;
      for(int i=1; i<=n; i++){
            x=-1;
            for(auto &e:edges){
                  if(dist[e.u]+e.w < dist[e.v]){
                        dist[e.v]= dist[e.u]+e.w;
                        parent[e.v]= e.u;
                        x= e.v;
                  }
            }
      }
      if(x==-1){
            cout<<"NO\n";
            return;
      }
      int y = x;
      for (int i = 0; i < n; i++)
      y = parent[y];

      vector<int> cycle;
      int cur = y;

      do {
      cycle.push_back(cur);
      cur = parent[cur];
      } while (cur != y);

      cycle.push_back(y);

    reverse(cycle.begin(), cycle.end());
    cout<<"YES\n";
    for (int v : cycle){
         cout << v << " ";
    }
    cout << "\n";
}
int main(){
      solve();
}