#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[20][2][2];
string num;
int count(int pos, bool tight, bool leading, int digit){
      if(pos == (int)num.size()){
            return 1;
      }
      if(!tight && dp[pos][0][leading] != -1){
            return dp[pos][0][leading];
      }
      int limit = tight ? num[pos]-'0' : 9;
      ll ans=0;
      for(int dig = 0; dig <= limit; dig++){
            bool newleading = leading && (dig==0);
            if(!newleading && dig== digit){
                  continue;
            }
            ans += count(pos + 1, tight && (dig == limit), newleading, digit);
      }
      if(!tight){
            dp[pos][0][leading] = ans;
      }
      return ans;
}
void solve(){
      int digit;
      cin >> num;
      cin >> digit;

      memset(dp, -1, sizeof(dp));

      cout << count(0, 1, 1, digit) << "\n";
}
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
      solve();
}