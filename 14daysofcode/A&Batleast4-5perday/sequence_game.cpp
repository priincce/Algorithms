#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
      ll n;
      cin>>n;
      ll maxi=LLONG_MIN, mini=LLONG_MAX;
      for(int i=0;i<n; i++){
            ll x;
            cin>>x;
            maxi= max(maxi, x);
            mini = min(mini, x);
      }
      int m;
      cin>>m;
      cout<<((maxi>= m && mini<= m)?"YES\n":"NO\n");

}
int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      cin >> t;
      while(t--){
            solve();
      }
      return 0;
}