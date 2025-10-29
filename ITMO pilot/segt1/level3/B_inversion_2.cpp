#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll foundPos;
vector<ll> freePos(100001);
void build(vector<ll>& arr, ll start, ll end, ll* tree, ll i) {
    if (start == end) {
        tree[i] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    build(arr, start, mid, tree, 2 * i);
    build(arr, mid + 1, end, tree, 2 * i + 1);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}
ll query(ll* tree, ll low, ll high, ll &k, ll i) {
    if (foundPos != -1 || tree[i] == 0) return INT_MAX;
    if (tree[i] < k) {
        k -= tree[i];
        return INT_MAX;
    }
    if (low == high) {
        foundPos = low;
        return low;
    }
    ll mid = (low + high) / 2;
    ll L = query(tree, low, mid, k, 2 * i);
    ll R = query(tree, mid + 1, high, k, 2 * i + 1);
    return min(L, R);
}
void update(ll* tree, ll low, ll high, ll pos, ll value, ll i) {
    if (pos < low || pos > high) return;
    if (low == high) {
        tree[i] = value;
        return;
    }
    ll mid = (low + high) / 2;
    update(tree, low, mid, pos, value, 2 * i);
    update(tree, mid + 1, high, pos, value, 2 * i + 1);
    tree[i] = tree[2 * i] + tree[2 * i + 1];
}
void solve() {
    ll n;
    cin >> n;
    ll tree[4 * n + 1] = {0};
    fill(freePos.begin(), freePos.end(), 1);
    build(freePos, 0, n - 1, tree, 1);
    vector<ll> inv(n);
    for (ll i = 0; i < n; i++) cin >> inv[i];
    ll remaining = n;
    vector<ll> p;
    for (ll i = n - 1; i >= 0; i--) {
        foundPos = -1;
        ll k = remaining - inv[i];
        ll pos = query(tree, 0, n - 1, k, 1);
        update(tree, 0, n - 1, pos, 0, 1);
        p.push_back(pos);
        remaining--;
    }
    reverse(p.begin(), p.end());
    for (ll pos : p) cout << pos + 1 << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
