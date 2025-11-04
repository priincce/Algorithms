
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>>dp;
void solve(string &s, string &t){
      dp.resize(n+1, vector<int>(m+1));

      for(int i=0;i<=n;i++){
            dp[i][0]=i;
      }
      for(int i=0;i<=m;i++){
            dp[0][i]=i;
      }
      for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(s[i-1]==t[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                  }else{
                        dp[i][j] = 1+ min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                  }
            }
      }
    cout << "Edit Distance: " << dp[n][m] << "\n";
    int i = n, j = m;
    vector<string> ops;

    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) {
            i--, j--; 
        }
        else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            ops.push_back("Replace '" + string(1, s[i - 1]) + "' with '" + string(1, t[j - 1]) + "'");
            i--, j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            ops.push_back("Delete '" + string(1, s[i - 1]) + "'");
            i--;
        }
        else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            ops.push_back("Insert '" + string(1, t[j - 1]) + "'");
            j--;
        }
    }

    reverse(ops.begin(), ops.end());
    for (auto &op : ops) cout << op << "\n";
}
int main(){
      string s, t;
      cin>>s>>t;
      n= s.size(), m = t.size();
      solve(s, t);
      cout<<dp[n][m]<<endl;
      return 0;
}
