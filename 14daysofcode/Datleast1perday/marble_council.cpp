#include<bits/stdc++.h>
#define ll long long
using namespace std; 
const int N=5e3+5;
const int mod=998244353;
ll a[N], dp[N], cnt[N];
int main(){
int t;cin>>t;
while(t--){

      ll n, ans=0, max_cnt=0;
      cin>>n;
      memset(cnt, 0, sizeof cnt);
      for(int i=1;i<=n;i++)
      {
            cin>>a[i];
            ++cnt[a[i]];
            max_cnt = max(max_cnt, cnt[a[i]]);
      }
      memset(dp, 0, sizeof dp);
      dp[0] = 1;
      for(int i=1;i<=n; i++){
            if(cnt[i]){
                  for(int j=n; j>=cnt[i]; --j){
                        dp[j]=(dp[j]+cnt[i]*dp[j-cnt[i]])%mod;
                  }
            }
      }
      for(int i=max_cnt; i<=n;i++){
            ans= (ans+dp[i])%mod;
      }
      cout<<ans<<endl;
      
}
return 0;
}