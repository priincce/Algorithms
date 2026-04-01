#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;
ll powr(ll a, ll b){
    ll r = 1;
    while(b){
        if(b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> p(m + 1);
        for(ll i = 0; i <= m; i++)
            p[i] = powr(i, n);

        ll sum = (m % MOD) * ((m + 1) % MOD) % MOD;
        sum = sum * powr(2, MOD - 2) % MOD; 
        ll p1 = n % MOD;
        p1 = p1 * powr(m, n - 1) % MOD;
        p1 = p1 * sum % MOD;

        ll p2 = 0;

        for(ll k = 1; k <= m; k++){
            ll cnt = (p[m - k + 1] - p[m - k] + MOD) % MOD;
            p2 = (p2 + (k % MOD) * cnt) % MOD;
        }
        ll ans = (p1 - p2 + MOD) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;

        if(q >= n) cout << 0 << "\n";
        else cout << (n - q) / 2 << "\n";
    }
    return 0;
}