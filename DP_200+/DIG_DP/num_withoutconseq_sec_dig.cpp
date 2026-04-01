#include <bits/stdc++.h>
#define ll long long
using namespace std;
string num;
int dp[20][10][2];

int count(int pos, int last_d, bool tight){
      if(pos==(int)num.size()){
            return 1;
      }
      if(dp[pos][last_d][tight] != -1){
            return dp[pos][last_d][tight];
      }
      int limit= tight ? num[pos] - '0' : 9;
      ll ans= 0;
      for(int d=0; d<= limit; d++){
            if(d== last_d) continue;
            ans += count(pos + 1, d, tight &&(d== limit));
      }
      return dp[pos][last_d][tight] = ans;
}

int solve(){
      cin >> num;
      int limit= num[0]-'0';
      ll ans=0;
      for(int d=1; d<=limit; d++){
            memset(dp, -1, sizeof dp);
            ans += count(1, d, d==limit);
      }
      cout << ans << endl;
}

int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      solve();
      return 0;
}
