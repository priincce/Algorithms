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
      vi v(n), wt(n);
      for(int i=0;i<n;i++){
            cin>>wt[i];
      }
      for(int i=0;i<n;i++){
            cin>>v[i];
      }
      vector<int>dp(W+1, 0);
      for(int i=0; i<n; i++){
            for(int w=W; w>=wt[i]; w--){
                  dp[w]= max(dp[w], v[i]+dp[w-wt[i]]);
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