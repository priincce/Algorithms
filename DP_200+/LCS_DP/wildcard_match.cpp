#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp1;

string s, t;
int n,m;
bool wildcard_memo(int i, int j){
      if(i==n && j==m)return true;
      if(j==m) return false;
      if(dp1[i][j]!=-1)return dp1[i][j];
      bool ans=false;

      if(t[j]=='*'){
            ans|=wildcard_memo(i, j + 1) || (i < n && wildcard_memo(i + 1, j));
      }
      else if(i < n && (t[j] == '?' || s[i] == t[j])){
            ans|=wildcard_memo(i + 1, j+1);
      }else{
            ans=false;
      }
      
      return dp1[i][j]= ans;
}
bool wildcard_tab(){
      dp1.assign(n+1, vector<int>(m+1, 0));
      dp1[0][0]=1;
      // base cases 
      for(int i=0;i<=n;i++){
            int flag=1;
            for(int k=0;k<=i-1;k++){
                  if(t[k] != '*'){
                        flag=0;
                        break;
                  }
            }
            dp1[i][0]=flag;
      }

      for(int i=1;i<=n;i++){
            for(int j=1; j<=m;j++){
                  if(s[i-1]==t[j-1]||t[j-1]=='?'){
                        dp1[i][j]=dp1[i-1][j-1];
                  }else if(t[j-1]=='*'){
                        dp1[i][j]=(dp1[i-1][j]||dp1[i][j-1]);
                  }else{
                        dp1[i][j]=0;
                  }
            }
      }
      return dp1[n][m];

}
bool solve_tab_opt(){
    vector<bool> prev(m + 1, false), curr(m + 1, false);
    prev[0] = true;
    for (int j = 1; j <= m; j++) {
        if (t[j - 1] == '*') prev[j] = prev[j - 1];
    }
    for (int i = 1; i <= n; i++) {
        curr[0] = false;
        for (int j = 1; j <= m; j++) {
            if (t[j - 1] == s[i - 1] || t[j - 1] == '?') {
                curr[j] = prev[j - 1];
            } else if (t[j - 1] == '*') {
                curr[j] = prev[j] || curr[j - 1];
            } else {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}
void solve(){
      cin>>s>>t;
      n= s.size(), m= t.size();
      // dp1.assign(n + 1, vector<int>(m + 1, -1));
      cout<< (solve_tab_opt() ? "YES" : "NO")<<"\n";
}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      // int t = 1;
      // cin >> t;
      // while(t--){
            solve();
      // }
      return 0;
}