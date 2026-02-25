#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dp[100005][2];
ll count(int pos, string& num, bool tight){
      if(pos==(int)num.size()){
            return 1;
      }
      if(dp[pos][tight] != -1){
            return dp[pos][tight];
      }
      int limit= tight?num[pos]-'0':9;
      ll ans=0;
      for(int digit = 0; digit <= limit; digit++){
            ans += count(pos+1, num, tight && (digit == limit));
      }
      if(!tight){
            dp[pos][tight] = ans;
      }
      return ans;
}
void solve() {
      string num;
      cin >> num;
      memset(dp, -1, sizeof(dp));
      cout<< count(0, num, 1)<< "\n";
}
int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      solve();
      return 0;
}