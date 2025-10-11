#include<bits/stdc++.h>
using namespace std;
using ll = long long;



// pre C++20
int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int main(){
      int n;cin>>n;
      vector<int>arr(n);
      for(auto &x:arr)cin >> x;
      // log precomputation
      vector<int>lg(n+1,0);
      for(int i=2;i<=n;i++){
            lg[i]= lg[i/2]+1;
      }


      int K = __lg(n);
      vector<vector<int>>st(K+1, vector<int>(n+1, 0));
      for(int i=0;i<n;i++){
            st[0][i]=arr[i];
      }
      for(int i=1;i<=K;++i){
            for(int j =0; j+(1<<i) <= n;++j){
                  st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
            }
      }

      auto query=[&](int l, int r){
          
            int i = lg[r-l+1];
            int ans =min(st[i][l],st[i][r-(1<<i)+1]);
            return ans;
      };
      int q;
      cin>>q;
      while(q--){
            int l, r;
      cin >>l>>r;
      cout<<query(l,r)<<endl;
      }
      return 0;
}