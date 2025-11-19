#include <bits/stdc++.h>
using namespace std;

int r, n, m;

struct mat {
    int a[2][2];
    mat() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
};
inline mat operation(const mat &x, const mat &y) {
    mat res;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            long long temp = 1LL * x.a[i][0] * y.a[0][j] + 1LL * x.a[i][1] * y.a[1][j];
            res.a[i][j] = int(temp % r); 
        }
    }
    return res;
}
inline mat make_identity() {
    mat I;
    I.a[0][0] = I.a[1][1] = 1;
    return I;
}

mat mi = make_identity();
vector<mat> seg, arr;

void build(int idx, int l, int r_) {
    if (l == r_) {
        seg[idx] = arr[l];
        return;
    }
    int mid = (l + r_) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r_);
    seg[idx] = operation(seg[idx * 2], seg[idx * 2 + 1]);
}

mat query(int idx, int l, int r_, int ql, int qr) {
    if (qr < l || ql > r_) return mi;
    if (ql <= l && r_ <= qr) return seg[idx];
    int mid = (l + r_) / 2;
    return operation(query(idx * 2, l, mid, ql, qr),
                     query(idx * 2 + 1, mid + 1, r_, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> r >> n >> m;

    arr.resize(n + 1);
    seg.resize(4 * n);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i].a[0][0] >> arr[i].a[0][1]
            >> arr[i].a[1][0] >> arr[i].a[1][1];
        arr[i].a[0][0] %= r; arr[i].a[0][1] %= r;
        arr[i].a[1][0] %= r; arr[i].a[1][1] %= r;
    }

    build(1, 1, n);

    ostringstream out;
    while (m--) {
        int l, rr;
        cin >> l >> rr;
        mat ans = query(1, 1, n, l, rr);
        out << ans.a[0][0] << " " << ans.a[0][1] << '\n'
            << ans.a[1][0] << " " << ans.a[1][1] << "\n\n";
    }
    cout << out.str();
    return 0;
}
