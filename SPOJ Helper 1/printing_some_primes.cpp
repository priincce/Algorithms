#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 100000000;  
    vector<bool> a(N + 1, true);

    a[0] = a[1] = false;

    for (int i = 2; i * 1LL * i <= N; i++) {
        if (a[i]) {
            for (int j = i * i; j <= N; j += i) {
                a[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (a[i]) {
            count++;
            if (count % 100 == 1)
                cout << i << "\n";
        }
    }

    return 0;
}
