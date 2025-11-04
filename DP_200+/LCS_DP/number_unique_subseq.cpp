#include<bits/stdc++.h>
using namespace std;
int n, MOD=1000000007;
void unique_subseq_naive(int ind, string &cur, unordered_set<string> &st, string &s) {
    if (ind == n) {
        st.insert(cur);
        return;
    }

    unique_subseq_naive(ind + 1, cur, st, s);

    cur.push_back(s[ind]);
    unique_subseq_naive(ind + 1, cur, st, s);
    cur.pop_back();
}

int countDistinctSubseq_DP(string &s) {
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    vector<int> last(26, -1);

    dp[0] = 1; 

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        int chIndex = s[i - 1] - 'a';
        if (last[chIndex] != -1) {
            dp[i] = (dp[i] - dp[last[chIndex] - 1] + MOD) % MOD;
        }
        last[chIndex] = i;
    }

    return dp[n];
}
int countDistinctSubseq_Optimal(string &s) {
    vector<long long> last(26, 0);
    long long dp = 1; 

    for (char c : s) {
        long long new_dp = (2 * dp % MOD - last[c - 'a'] + MOD) % MOD;
        last[c - 'a'] = dp;
        dp = new_dp;
    }

    return dp;
}
int unique_subseq(string &s){

}
int main(){
      string s;
      n = s.size();
      int ans = unique_subseq(s);
      cout<<ans<<"\n";
      return 0;
}