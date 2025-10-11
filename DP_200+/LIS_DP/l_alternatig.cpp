#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
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


int fn(vi&arr, int index, int diff,umap<int, umap<int, int>>&dp){
      if(index==0)return 1;
      if(dp[index].count(diff))return dp[index][diff];
      int ans=0;
      for(int prev=index-1;prev>=0; prev--){
            if((arr[index]- arr[prev])==diff ){
                  ans= max(ans, 1+fn(arr, prev, diff, dp));
            }
      }
      return dp[index][diff]=ans;
}
int solve(vi&arr){
      int n= arr.size();
      vvi dp(n, vi(2, 1));
      int ans=0;
      for(int i=1;i<n;i++){
            for(int prev=0;prev<i; prev++){
                  if(arr[i]>arr[prev] && dp[i][0] < dp[prev][1]+1){
                        dp[i][0]= 1+ dp[prev][1];
                  }
                  if(arr[i]<arr[prev] && dp[i][1] < dp[prev][0]+1){
                        dp[i][1]=1+ dp[prev][0];
                  }
            }
            if (ans< max(dp[i][0], dp[i][1])){
                  ans = max(dp[i][0], dp[i][1]);
            }
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