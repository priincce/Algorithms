#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define vpi vector<pi>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mod 1000000007
#define debug0 {cout<<1<<"\n"; return;}
#define debug1 {cout<<1<<"\n"; return 0;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), mp(60, 0);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        for (int b = 0; b < 60; b++) {
            if(((a[i] >> b) & 1)){
                  ++mp[b];
            }
        }
    }

    ll ans = 0;
    for (ll j = 0; j < n; j++) {
        ll aval = 0, oval = 0;
        ll c = a[j];

        for (int b = 0; b < 60; b++) {
            ll p2 = (1LL << b) % mod;
            if ((c >> b) & 1) {
                aval = (aval + p2 * mp[b]) % mod;
                oval = (oval + p2 * n) % mod;  
            } else {
                oval = (oval + p2 * mp[b]) % mod;
            }
           
        }
         ans = (ans + (oval * aval)) % mod;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
