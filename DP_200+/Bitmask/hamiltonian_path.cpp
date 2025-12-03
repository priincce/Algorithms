#include<bits/stdc++.h>
using namespace std;

// hamiltonian path - NP complete problem 
// each vertex exatly one time visited in a graph if such path exist then it will be called hamiltonian path
int n, m;
vector<vector<int>>graph;
map<pair<int, set<int>>, bool>mp;
bool dp(int node, set<int>st){
      if(st.size()==n){
            return true;
      }
      if(mp.count({node, st})){
            return mp[{node, st}];
      }
      bool ans=false;
      for(auto nb:graph[node]){
            if(st.find(nb) ==st.end()){
                  set<int>temp=st;
                  temp.insert(nb);
                  ans|=dp(nb, temp);
            }
      }
      return mp[{node, st}]=ans;
}
int main(){
      cin>>n>>m;
      graph.resize(n);
      for(int i=0; i<m; i++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);
      }
      // we will try all permutation for finding  the possible combination then we will stop 
      bool path =false;
      for(int i=0; i<n; i++){
            set<int >st;
            st.insert(i);
            path|=dp(i, st);
      }
      cout<<path<<endl;
      return 0;
}