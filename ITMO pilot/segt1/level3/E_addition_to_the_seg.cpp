#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> seg;

void update(ll index, ll low, ll high, ll l, ll r, ll val) {
    if (r < low || high < l) return; 
    if (l <= low && high <= r) {
        seg[index] += val; 
        return;
    }
    ll mid = (low + high) / 2;
    update(2 * index + 1, low, mid, l, r, val);
    update(2 * index + 2, mid + 1, high, l, r, val);
}

ll query(ll index, ll low, ll high, ll pos) {
    if (low == high) return seg[index]; 
    ll mid = (low + high) / 2;
    if (pos <= mid)
        return seg[index] + query(2 * index + 1, low, mid, pos);
    else
        return seg[index] + query(2 * index + 2, mid + 1, high, pos);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    seg.assign(4 * n, 0);

    while (q--) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            update(0, 0, n - 1, l, r-1, val);
        } else {
            ll pos;
            cin >> pos;
            cout << query(0, 0, n - 1, pos) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
