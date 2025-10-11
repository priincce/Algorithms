#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,q;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    int MOD = __lg(n);
    vector<vector<ll>> st(MOD + 1, vector<ll>(n));


    for (int i = 0; i < n; ++i)
        st[0][i] = arr[i];


    for (int i = 1; i <= MOD; ++i) {
        for (int j = 0; j + (1 << i) <= n; ++j) {
            st[i][j] = st[i - 1][j] + st[i - 1][j + (1 << (i - 1))];
        }
    }

    auto sum = [&](int l, int r) {
        ll ans = 0;
        for (int i = MOD; i >= 0; --i) {
            if ((1 << i) <= r - l + 1) {
                ans += st[i][l];
                l += (1 << i);
            }
        }
        return ans;
    };

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << sum(--l, --r) << endl;
    }

    return 0;
}
