#include<bits/stdc++.h>
using namespace std;

// hamiltonian path - NP complete problem 
// each vertex exatly one time visited in a graph if such path exist then it will be called hamiltonian path





// here for n node we use mask as 2^n -1

int n, m;
vector<vector<int>>graph;
vector<vector<int>>memo;
bool dp(int node,int  mask){
      if(mask==(1<<n)-1){
            return true;
      }
      if(memo[node][mask] != -1){
            return memo[node][mask];
      }
      bool ans=false;
      for(auto nb:graph[node]){
            if(!((mask>>nb) & 1)){
                  ans|=dp(nb, mask | (1<<nb));
            }
      }
      return memo[node][mask]=ans;
}
int main(){
      cin>>n>>m;
      graph.resize(n);
      memo.resize(n, vector<int>((1<<n), -1));
      for(int i=0; i<m; i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
      }
      bool path =false;
      for(int i=0; i<n; i++){
            path|=dp(i, (1<<i));
      }
      cout<<path<<endl;
      return 0;
}