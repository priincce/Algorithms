#include <bits/stdc++.h>
using namespace std;

int n;
int solve_tab(string &s){
      vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
      for(int i=1;i<=n; i++){
      for(int j =1; j<=n;j++){
            if(s[i-1]==s[j-1] && i!= j){
                  dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
      }
      }
      return dp[n][n];
}
int longest_rep_subseq(string s) {
      n= s.size();
      return solve_tab(s);
}



int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            
      }
      return 0;
}

