#include<bits/stdc++.h>
using namespace std;
int n, m, start=-1;
unordered_map<int, deque<int>>adj;
unordered_map<int, int>ind, out;
vector<int>res;

signed main(){
      cin>>n>>m;
     for(int i=0; i<m; i++){
        int u, v;
        cin>> u>> v;
        if(start==-1)start=u;
        adj[u].push_back(v);
        ind[v]++;
        out[u]++;
     }
     int startnode =-1;
      for(const auto &entry:out){
            int node=entry.first;
            if(out[node]== ind[node]+1){
                  startnode= node;
                  break;
            }
      }
      if(startnode ==-1){
            startnode =start;
      }
      
        stack<int>dfs;
        dfs.push(startnode);
        while(!dfs.empty()){
            int node =dfs.top();
            if(!adj[node].empty()){
                int nextnode = adj[node].front();
                adj[node].pop_front();
                dfs.push(nextnode);
            }else{
                res.push_back(node);
                dfs.pop();
            }
        }
        reverse(res.begin(), res.end());
        
     return 0;

}