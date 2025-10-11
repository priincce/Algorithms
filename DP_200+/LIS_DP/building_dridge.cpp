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


int solve(vpi&temp){
      int n= temp.size();
      sort(temp.begin(), temp.end(), [](const pi&a, const pi &b){
            if(a.second == b.second){
                  return a.first < b.first;
            }
            return  a.second < b.second;

      });
      vi dp(n, 1);
      int ans =0;
      for(int i=1; i<n;i++){
            for(int prev= 0 ; prev<i; prev++){
                  if(temp[i].first >= temp[prev].first && dp[i]< dp[prev]+1){
                        dp[i] = 1+dp[prev];
                  }
            }
            ans = max(ans, dp[i]);
      }
      return ans;
      
}
int solve_opti(vpi&temp){
      sort(temp.begin(), temp.end());
      int n=temp.size(), ans=0;
      vi dp(n, INT_MAX);
      for(int i=0;i<n;i++){
            int ind = (lower_bound(temp.begin(), temp.end(), temp[i].second)-temp.begin());
            dp[ind]= temp[i].second;
            ans= max(ans, ind+1);
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