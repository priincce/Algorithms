#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
      ll n;
    cin >> n;
    ll s = 0, mn = 0, bst = 0;
    for (ll i = 0; i < n; ++i) {
      ll x;
      cin >> x;
      s += x;
      ll cur = (i + 1) *(i + 2) - s;
      mn = min(mn, cur);
      bst = max(bst, cur - mn);
    }
    cout << s + bst << '\n';
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