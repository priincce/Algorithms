#include <bits/stdc++.h>
using namespace std;

int n, m;
string solve_tab(string &s, string &t){
      vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
      for(int i=1;i<=n; i++){
      for(int j =1; j<=m;j++){
            if(s[i-1]==t[j-1]){
                  dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                  dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
      }
      }
      int i= n, j = m;
      string ans="";
      while(i>0 && j>0){
      if(s[i-1]==t[j-1]){
            ans=s[i-1]+ans;
            i--;
            j--;
      }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
      }else{
            j--;
      }
      }
      return ans;
}
string longestCommonSubsequence(string text1, string text2) {
      n= text1.size(), m = text2.size();
      return solve_tab(text1, text2);
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

