#include<bits/stdc++.h>
using namespace std;

// hamiltonian path - NP complete problem 
// each vertex exatly one time visited in a graph if such path exist then it will be called hamiltonian path





// here for n node we use mask as 2^n -1

int n, m;

int main(){
      cin>>n>>m;

      vector<int>graph[n];
      int dp[n][1<<n];
      memset(dp, 0, sizeof dp);

      for(int i=0; i<m; i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
      }
      
      bool path =false;
      for(int i=0; i<n; i++){
            dp[i][1<<i]=1;
      }
      for(int mask =0; mask<(1<<n) ; mask++){
            for(int cur =0; cur<n; cur++){
                  if(dp[cur][ mask]){
                        for(auto x:graph[cur]){
                              if(!((mask>>x)&1)){
                                    dp[x][mask |(1<<x)]=true;
                              }
                        }
                  }
            }
      }
      for(int i=0; i<n; i++){
            path|=dp[i][(1<<n)-1];
      }
      cout<<path<<endl;
      return 0;
}