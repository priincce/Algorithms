#include <bits/stdc++.h>
using namespace std;

int n, m;
    vector<vector<int>>dp;
    int solve_memo(int i, int j, string&s, string &t)
    {
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(s[i]==t[j]){
            ans= 1+ solve_memo(i+1, j+1, s, t);
        }else{
            ans= max(solve_memo(i+1, j, s, t), solve_memo(i, j+1, s, t));
        }
        return dp[i][j] = ans;
    }

    int solve_tab(string &s, string &t){
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
        return dp[n][m];
    }
    int longestCommonSubsequence(string &text1, string &text2) {
        n= text1.size(), m = text2.size();
        // dp.resize(n, vector<int>(m, -1));
        // return solve(0, 0, text1, text2);
        return solve_tab(text1, text2);
    }

void solve(){
    string a, b;
    cin>>a>>b;
    cout<<longestCommonSubsequence(a, b);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
    //   while(t--){
         solve();   
    //   }
      return 0;
}

