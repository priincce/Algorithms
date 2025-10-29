#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 10000000;
    vector<bool> is_prime(MAX + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; 1LL * i * i <= MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX; j += i) is_prime[j] = false;
        }
    }
    vector<char> is_good(MAX + 1, 0);
    int max_y = 1;
    while (1LL * max_y * max_y * max_y * max_y <= MAX) ++max_y;
    --max_y; 

    for (int y = 0; y <= max_y; ++y) {
        long long y4 = 1LL * y * y * y * y;
        for (int x = 0;; ++x) {
            long long val = 1LL * x * x + y4;
            if (val > MAX) break;
            if (is_prime[(int)val]) is_good[(int)val] = 1;
        }
    }
    vector<int> pref(MAX + 1, 0);
    for (int i = 1; i <= MAX; ++i) pref[i] = pref[i-1] + (is_good[i] ? 1 : 0);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        if (n > MAX) n = MAX;
        cout << pref[n] << '\n';
    }
    return 0;
}
