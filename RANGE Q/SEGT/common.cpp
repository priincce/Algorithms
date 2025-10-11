#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int a[N]; 
int seg[4 * N]; 

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0; 
    if (ql <= l && r <= qr) return seg[idx]; 
    int mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) +
           query(2 * idx + 1, mid + 1, r, ql, qr);
}
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, val);
    else
        update(2 * idx + 1, mid + 1, r, pos, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int main() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n - 1);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << "\n";
        } else {
            int pos, val;
            cin >> pos >> val;
            update(1, 0, n - 1, pos, val);
        }
    }

    return 0;
}
