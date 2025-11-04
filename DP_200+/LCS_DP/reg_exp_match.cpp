#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
string s, t;
int n, m;
bool memo(int i, int j){
    if(i==n && j==m) return true;
    if(j==m) return false;
    if(dp[i][j] != -1) return dp[i][j];
    bool first_match = (i<n && (s[i]==t[j] || t[j]=='.'));
    if(j+1 <m && t[j+1]=='*'){
        return dp[i][j]=memo(i, j+2) || (first_match && memo(i+1, j));
    }else{
        return dp[i][j] = first_match && memo(i+1, j+1);
    }
}
bool tab(){
    dp.assign(n+1, vector<int>(m+1, 0));
    dp[n][m]=1;
    for(int i=n;i>=0;i--){
        for(int j=m-1; j>=0; j--){
            bool firstMatch = (i < n && (s[i] == t[j] || t[j] == '.'));

            if (j + 1 < m && t[j + 1] == '*')
                dp[i][j] = dp[i][j + 2] || (firstMatch && dp[i + 1][j]);
            else
                dp[i][j] = firstMatch && dp[i + 1][j + 1];
        }
    }
    return dp[0][0];
}
bool space_optimised(){
    vector<bool> next(m + 1, false), curr(m + 1, false);
    next[m] = true;
    for (int i = n; i >= 0; i--){
        curr[m] = (i == n);
        for (int j = m - 1; j >= 0; j--){
            bool firstMatch = (i < n && (s[i] == t[j] || t[j] == '.'));
            if (j + 1 < m && t[j + 1] == '*')
                curr[j] = (next[j] && firstMatch) || curr[j + 2];
            else
                curr[j] = firstMatch && next[j + 1];
        }
        next = curr;
    }
    return next[0];
}
void solve(){
      cin>>s>>t;
      n = s.size(), m = t.size();
    //   dp.assign(n+1, vector<int>(m+1, -1));
      cout<<(space_optimised()?"YES":"NO")<< "\n";

}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

    //   int t = 1;
    //   cin >> t;
    //   while(t--){
            solve();
    //   }
      return 0;
}