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
    seg[i] = max(seg[i * 2] , seg[i * 2 + 1]);
}

void update(int pos, int i, int l, int h,int val) {
    if (l == h) {
        a[pos] =val;
        seg[i] = a[pos];
        return;
    }
    int mid = l + (h - l) / 2;
    if (pos <= mid) {
        update(pos, i * 2, l, mid, val);
    } else {
        update(pos, i * 2 + 1, mid + 1, h, val);
    }
    seg[i] = max(seg[i * 2] , seg[i * 2 + 1]);
}

int query( int i, int l, int h, int val) {
    if (seg[i] < val) {
        return -1;
    }

    // BASE CASE: If we reach a leaf, we have found our element.
    if (l == h) {
        return l;
    }

    int mid = l + (h - l) / 2;
    
    if (seg[i * 2] >= val) {
        return query( i * 2, l, mid, val);
    } 
    else {
        return query( i * 2 + 1, mid + 1, h, val);
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
            int pos, val;
            cin >> pos>>val;
            update(pos, 1, 0, n - 1, val);
        } else {
            int val;
            cin >> val;
            cout << query( 1, 0, n - 1, val) << "\n";
        }
    }
    return 0;
}
