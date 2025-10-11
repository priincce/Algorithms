#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
void solve(){
      int n, W;
      cin>>n>>W;
      vi v(n), wt(n), Lim(n);
      for(int i=0;i<n;i++){
            cin>>wt[i];
      }
      for(int i=0;i<n;i++){
            cin>>v[i];
      }
      for(int i=0;i<n;i++){
            cin>>Lim[i];
      }
      vector<int>dp(W+1, 0);
      for(int i=0; i<n; i++){
            int cnt = Lim[i];
            int k = 1;
            while (cnt > 0) {

                  int take = min(k, cnt);
                  int weight = take * wt[i];
                  int value = take * v[i];

                  for (int w = W; w >= weight; w--) {
                        dp[w] = max(dp[w], dp[w - weight] + value);
                  }
                  cnt -= take;
                  k <<= 1;
            }
      }
      cout<<dp[W]<<endl;
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}