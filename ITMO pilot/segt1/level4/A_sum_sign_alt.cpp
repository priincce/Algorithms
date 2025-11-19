#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> seg;
vector<ll> arr;
ll n;

void build(ll idx, ll l, ll r) {
    if (l == r) {
        seg[idx] = ((l % 2) ? arr[l] : -arr[l]);
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

void update(ll idx, ll l, ll r, ll pos, ll val) {
    if (l == r) {
        arr[l] = val;
        seg[idx] = ((l % 2) ? val : -val);
        return;
    }
    ll mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, val);
    else
        update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

ll query(ll idx, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return seg[idx];
    ll mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr)
         + query(2 * idx + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++) cin >> arr[i];
    seg.assign(4 * n, 0);
    build(1, 1, n);

    ll m; cin >> m;
    while (m--) {
        ll type; cin >> type;
        if (type == 0) {
            ll i, j;
            cin >> i >> j;
            update(1, 1, n, i, j);
        } else {
            ll l, r;
            cin >> l >> r;
            ll ans = query(1, 1, n, l, r);
            // adjust final sign based on start index
            if (l % 2 == 0) ans = -ans;
            cout << ans << "\n";
        }
    }
    return 0;
}
