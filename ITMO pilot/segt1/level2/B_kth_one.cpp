#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int n, q;
vector<int> seg, a;

void build(int i, int l, int h) {
    if (l == h) {
        seg[i] = a[l];
        return;
    }
    int mid = l + (h - l) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, h);
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

void update(int pos, int i, int l, int h) {
    if (l == h) {
        a[pos] ^= 1;
        seg[i] = a[pos];
        return;
    }
    int mid = l + (h - l) / 2;
    if (pos <= mid) {
        update(pos, i * 2, l, mid);
    } else {
        update(pos, i * 2 + 1, mid + 1, h);
    }
    seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

int query(int k, int i, int l, int h) {
    if (l == h) {
        return l;
    }
    int mid = l + (h - l) / 2;
    int left_child_count = seg[i * 2];
    if (k < left_child_count) {
        return query(k, i * 2, l, mid);
    } else {
        return query(k - left_child_count, i * 2 + 1, mid + 1, h);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    seg.resize(4 * n);
    build(1, 0, n - 1);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx;
            cin >> idx;
            update(idx, 1, 0, n - 1);
        } else {
            int k;
            cin >> k;
            cout << query(k, 1, 0, n - 1) << "\n";
        }
    }
    return 0;
}
