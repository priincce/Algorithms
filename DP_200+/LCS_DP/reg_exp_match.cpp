#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pp pop_back
#define umap unordered_map
#define uset unordered_set
#define sort(arr) sort(all(arr))
#define min(arr) (*min_element(all(arr)))
#define max(arr) (*max_element(all(arr)))
#define lb(arr, x) (lower_bound(all(arr), (x)) - (arr).begin())
#define ub(arr, x) (upper_bound(all(arr), (x)) - (arr).begin())
const int MAXN = 1e5;
ll fact[MAXN + 1], invFact[MAXN + 1];
const int MOD = 1e9 + 7;
ll modExp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
void precompute_factorial() {
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modExp(fact[i], MOD - 2, MOD);
    }
}
ll nCr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}
ll nPr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (fact[n] * invFact[n - r]) % MOD;
}
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}
ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}



void solve()
{
      int n;
      cin >> n;
      vector<int>nums(n);
      cout<< n<< endl;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);

      int t = 1;
      // cin >> t;
      while(t--){
            solve();
      }
      return 0;
}

