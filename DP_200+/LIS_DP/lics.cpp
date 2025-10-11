#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pp pop_back
#define umap unordered_map
#define uset unordered_set
#define lb(arr, x) (lower_bound(all(arr), (x)) - (arr).begin())
#define ub(arr, x) (upper_bound(all(arr), (x)) - (arr).begin())


int fn(vi&a, vi&b, int i, int j, int prev, vvvi&dp){
      if(i<0 || j<0) return 0;
      if(dp[i][j][prev+1] != -1) return dp[i][j][prev+1];
      int included =0, excluded=0;
      if(a[i]==b[j] && (prev==-1 || a[i] <a[prev])){
            included = 1+fn(a, b, i-1, j-1, i, dp);
      }
      excluded= max(fn(a, b, i-1, j, prev, dp), fn(a, b, i, j-1, prev, dp));
      
      return dp[i][j][prev+1] = max(included, excluded);
}
int solve(vi&a, vi&b){

  
      int n= a.size(), m= b.size();
      vi dp(n, 0);
      int ans=0;
      for(int i=0;i<n;i++){
            int curlen=0;
            for(int j=0;j< n; j++){
                  if(a[i]==b[j]){
                        dp[i] = max(curlen+1, dp[j]);
                  }else if(a[i] > b[j]) {
                        dp[i]= max(curlen, dp[j]);
                  }
            }
            ans = max(ans, dp[i]);
      }
      return ans;
      
}
int solve_tab(vi&arr){
      int n=arr.size();
      if(n<=2)return n;
      int ans=0;
      umap<int, umap<int, int>>dp;
      for(int i=1; i<n;i++){
            for(int prev = 0; prev<i; prev++){
                  int diff= arr[i]-arr[prev];
                  dp[i][diff]= dp[i].count(diff)?1+dp[prev][diff]:2;
                  ans= max(ans, dp[i][diff]);
            }
      }
      return ans;  
}
void solve(){
      
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}