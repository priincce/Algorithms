#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

long long countSubsequenceWays(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for (int j = 0; j <= m; j++)
        dp[0][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % MOD;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[n][m];
}

int main() {
    string a = "aba", b = "ababa";
    cout << countSubsequenceWays(a, b) << endl;
    return 0;
}
