#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[20][2];
string num;

ll countDP(int pos, bool tight, int digit){
      if(pos == (int)num.size())
            return 1;

      if(!tight && dp[pos][0] != -1)
            return dp[pos][0];

      int limit = tight ? num[pos]-'0' : 9;
      ll ans = 0;

      for(int dig = 0; dig <= limit; dig++){
            if(dig == digit) continue;
            ans += countDP(pos + 1, tight && (dig == limit), digit);
      }

      if(!tight)
            dp[pos][0] = ans;

      return ans;
}

void solve() {
      int digit;
      cin >> num;
      cin >> digit;

      memset(dp, -1, sizeof(dp));

      cout << countDP(0, 1, digit) << "\n";
}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      solve();
      return 0;
}