#include<bits/stdc++.h>
const int MAXN=1e5;
int subtree_size[MAXN];
bool removed[MAXN];
std::vector<int> adj[MAXN];
int centroid_parent[MAXN];
int K;
long long ans=0;

// step 1
int get_subtree_size(int v, int p =-1){
      subtree_size[v]= 1;
      for(auto u: adj[v]){
            if(u==p || removed[u]) continue;
            get_subtree_size(u, v);
            subtree_size[v]+=subtree_size[u];
      }
      return subtree_size[v];
}
// step 2

int get_centeroid(int v, int tree_size, int p =-1){
      for(auto u: adj[v]){
            if(u==p || removed[u]) continue;
            if(subtree_size[u] * 2 > tree_size ){
                  return get_centeroid(u, tree_size, v);
            }
      }
      return v;
}
// step 3

void  get_distance(int v, int p, int dist, std::vector<int>&distances){
      if(dist > K) return;
      distances.push_back(dist);
      for(auto u: adj[v]){
            if(u==p || removed[u]) continue;
            get_distance(u, v, dist+1, distances);
      }
}
// step 4

void process_centeroid(int centeroid){
      std::unordered_map<int , int>all_distances;
      all_distances[0]=1;

      for(int u: adj[centeroid]){
            if(removed[u]) continue;

            std::vector<int>current_distances;
            get_distance(u, centeroid, 1, current_distances);

            for(int d: current_distances){
                  if( K- d >0){
                        ans += (all_distances[K-d]? all_distances[K-d] : 0);
                  }
            }

            for(int d: current_distances){
                  if(all_distances.find(d)== all_distances.end()){
                        all_distances[d]=0;
                  }
                  all_distances[d]++;
            }
      }
}
// step 5

void decompose(int v, int p =-1){
      int tree_size = get_subtree_size(v);
      int centeroid = get_centeroid(v, tree_size);

      process_centeroid(centeroid);
      // centroid_parent[centeroid]=p; // for quering the ans
      removed[centeroid] = true;
      for(int u: adj[centeroid]){
            if(!removed[u]){
                  decompose(u, centeroid);
            }
      }
      // return centroid; // for return type int
}

int main(){

}