#include <bits/stdc++.h>
#define int long long 
using namespace std;

int n;
vector<int> seg;

void update(int pos, int i, int l, int r, int val) {
    if (l == r) {
        seg[i] += val;   
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(pos, i*2, l, mid, val);
    else update(pos, i*2+1, mid+1, r, val);
    seg[i] = seg[i*2] + seg[i*2+1];
}

int query(int i, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;  
    if (ql <= l && r <= qr) return seg[i]; 
    int mid = (l + r) / 2;
    return query(i*2, l, mid, ql, qr) + query(i*2+1, mid+1, r, ql, qr);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    seg.assign(4*n, 0);
    vector<int> ans(n+1);

    for (int i = 1; i <= n; i++) {
        ans[i] = query(1, 1, n, p[i]+1, n);
        update(p[i], 1, 1, n, 1);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << "\n";
}
