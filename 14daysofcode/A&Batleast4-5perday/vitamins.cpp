#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const long long INF = 4e18;
    vector<long long> best(8, INF);

    while (n--) {
        long long c;
        string s;
        cin >> c >> s;
        int mask = 0;
        for (char ch : s) {
            if (ch == 'A') mask |= 1;
            else if (ch == 'B') mask |= 2;
            else if (ch == 'C') mask |= 4;
        }
        best[mask] = min(best[mask], c);
    }

    long long ans = best[7]; 

    for (int i = 1; i < 8; i++) {
        if (best[i] == INF) continue;
        for (int j = 1; j < 8; j++) {
            if (best[j] == INF) continue;
            if ((i | j) == 7) ans = min(ans, best[i] + best[j]);
        }
    }

    for (int i = 1; i < 8; i++) {
        if (best[i] == INF) continue;
        for (int j = 1; j < 8; j++) {
            if (best[j] == INF) continue;
            for (int k = 1; k < 8; k++) {
                if (best[k] == INF) continue;
                if ((i | j | k) == 7)
                    ans = min(ans, best[i] + best[j] + best[k]);
            }
        }
    }

    if (ans >= INF) cout << -1;
    else cout << ans;
}
